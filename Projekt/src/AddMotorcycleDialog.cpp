#include "AddMotorcycleDialog.hpp"

#include <QPushButton>

#include "Motorcycle.hpp"

AddMotorcycleDialog::AddMotorcycleDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.buttonBox->button(QDialogButtonBox::Save), &QPushButton::released, this, &AddMotorcycleDialog::finish);
	connect(ui.buttonBox->button(QDialogButtonBox::Cancel), &QPushButton::released, this, &AddMotorcycleDialog::cancel);
}

AddMotorcycleDialog::~AddMotorcycleDialog() {}

void AddMotorcycleDialog::finish()
{
	const auto manufacturer = ui.manufacturerEditText->toPlainText();
	const auto model = ui.modelEditText->toPlainText();
	const auto productionYearStr = ui.productionYearEditText->toPlainText();
	const uint16_t productionYear = productionYearStr.toShort();
	const auto transmission = ui.transmissionCombobox->currentIndex();
	const auto fuelType = ui.fuelTypeCombobox->currentIndex();
	const float capacity = ui.capacitySpinbox->value();
	const auto power = ui.powerSpinbox->value();

	if (manufacturer.isEmpty() or model.isEmpty() or 0 == productionYear or -1 == transmission or -1 == fuelType)
	{
		msgBox = std::make_shared<QMessageBox>(QMessageBox::Icon::Warning, tr("error"), tr("missing_fields"), QMessageBox::Ok, this);
		msgBox->show();
		return;
	}

	VehicleParameters params{
		{},
		productionYear,
		static_cast<float>(ui.pricePerHourSpinbox->value()),
		static_cast<float>(ui.pricePerDaySpinbox->value()),
		manufacturer.toStdString(),
		model.toStdString()
	};

	MotorizedVehicleParameters motorizedParams{
		MotorizedVehicle::Drive::rear,
		static_cast<MotorizedVehicle::Transmission>(transmission),
		MotorizedVehicle::EngineSpec{
		    capacity,
			static_cast<uint16_t>(power),
			static_cast<MotorizedVehicle::EngineSpec::FuelType>(fuelType)
		}
	};

	motorcycle = std::make_shared<Motorcycle>(params, motorizedParams);

	accept();
}

void AddMotorcycleDialog::cancel()
{
	reject();
}

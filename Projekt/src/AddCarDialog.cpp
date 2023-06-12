#include "AddCarDialog.hpp"

#include <QMessageBox>
#include <QPushButton>

#include "Car.hpp"

AddCarDialog::AddCarDialog(QWidget* parent) : QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.buttonBox->button(QDialogButtonBox::Save), &QPushButton::released, this, &AddCarDialog::finish);
	connect(ui.buttonBox->button(QDialogButtonBox::Cancel), &QPushButton::released, this, &AddCarDialog::cancel);
}

void AddCarDialog::finish()
{
	const auto manufacturer = ui.manufacturerEditText->toPlainText();
	const auto model = ui.modelEditText->toPlainText();
	const auto productionYearStr = ui.productionYearEditText->toPlainText();
	const uint16_t productionYear = productionYearStr.toShort();
	const auto transmission = ui.transmissionCombobox->currentIndex();
	const auto fuelType = ui.fuelTypeCombobox->currentIndex();
	const float capacity = ui.capacitySpinbox->value();
	const auto power = ui.powerSpinbox->value();
	const auto drive = ui.driveCombobox->currentIndex();

	if (manufacturer.isEmpty() or model.isEmpty() or 0 == productionYear or -1 == transmission or -1 == fuelType or -1 == drive)
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
		static_cast<MotorizedVehicle::Drive>(drive),
		static_cast<MotorizedVehicle::Transmission>(transmission),
		MotorizedVehicle::EngineSpec{
			capacity,
			static_cast<uint16_t>(power),
			static_cast<MotorizedVehicle::EngineSpec::FuelType>(fuelType)
		}
	};

	car = std::make_shared<Car>(params, motorizedParams);

	accept();
}

void AddCarDialog::cancel()
{
	reject();
}

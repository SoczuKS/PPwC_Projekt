#include "AddScooterDialog.hpp"

#include <QMessageBox>
#include <QPushButton>

#include "Scooter.hpp"

AddScooterDialog::AddScooterDialog(QWidget* parent) : QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.buttonBox->button(QDialogButtonBox::Save), &QPushButton::released, this, &AddScooterDialog::finish);
	connect(ui.buttonBox->button(QDialogButtonBox::Cancel), &QPushButton::released, this, &AddScooterDialog::cancel);
}

void AddScooterDialog::finish()
{
	const auto manufacturer = ui.manufacturerEditText->toPlainText();
	const auto model = ui.modelEditText->toPlainText();
	const auto productionYearStr = ui.productionYearEditText->toPlainText();
	const uint16_t productionYear = productionYearStr.toShort();

	if (manufacturer.isEmpty() or model.isEmpty() or 0 == productionYear)
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

	scooter = std::make_shared<Scooter>(params);

	accept();
}

void AddScooterDialog::cancel()
{
	reject();
}

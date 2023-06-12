#include "AddBikeDialog.hpp"

#include <QMessageBox>
#include <QPushButton>

#include "Bike.hpp"

AddBikeDialog::AddBikeDialog(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.buttonBox->button(QDialogButtonBox::Save), &QPushButton::released, this, &AddBikeDialog::finish);
	connect(ui.buttonBox->button(QDialogButtonBox::Cancel), &QPushButton::released, this, &AddBikeDialog::cancel);
}

AddBikeDialog::~AddBikeDialog() {}

void AddBikeDialog::finish()
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

	bike = std::make_shared<Bike>(params);

	accept();
}

void AddBikeDialog::cancel()
{
	reject();
}

#pragma once

#include "ui_AddScooterDialog.h"

class QMessageBox;

class Scooter;

class AddScooterDialog final : public QDialog
{
	Q_OBJECT

public:
	AddScooterDialog(QWidget* parent = nullptr);
	~AddScooterDialog() override = default;

	std::shared_ptr<Scooter> getScooter() const { return scooter; }

private slots:
	void finish();
	void cancel();

private:
	Ui::AddScooterDialogClass ui;
	std::shared_ptr<QMessageBox> msgBox;

	std::shared_ptr<Scooter> scooter;
};

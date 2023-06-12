#pragma once

#include <QDialog>
#include <QMessageBox>

#include "ui_AddScooterDialog.h"

class Scooter;

class AddScooterDialog : public QDialog
{
	Q_OBJECT

public:
	AddScooterDialog(QWidget *parent = nullptr);
	~AddScooterDialog();

	std::shared_ptr<Scooter> getScooter() const { return scooter; }

private slots:
	void finish();
	void cancel();

private:
	Ui::AddScooterDialogClass ui;
	std::shared_ptr<QMessageBox> msgBox;

	std::shared_ptr<Scooter> scooter;
};

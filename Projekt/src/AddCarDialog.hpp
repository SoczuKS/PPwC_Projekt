#pragma once

#include <QDialog>
#include <QMessageBox>

#include "ui_AddCarDialog.h"

class Car;

class AddCarDialog : public QDialog
{
	Q_OBJECT

public:
	AddCarDialog(QWidget *parent = nullptr);
	~AddCarDialog();

	std::shared_ptr<Car> getCar() const { return car; }

private slots:
	void finish();
	void cancel();

private:
	Ui::AddCarDialogClass ui;
	std::shared_ptr<QMessageBox> msgBox;

	std::shared_ptr<Car> car;
};

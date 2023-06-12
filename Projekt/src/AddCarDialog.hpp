#pragma once

#include "ui_AddCarDialog.h"

class QMessageBox;

class Car;

class AddCarDialog final : public QDialog
{
	Q_OBJECT

public:
	AddCarDialog(QWidget* parent = nullptr);
	~AddCarDialog() override = default;

	std::shared_ptr<Car> getCar() const { return car; }

private slots:
	void finish();
	void cancel();

private:
	Ui::AddCarDialogClass ui;
	std::shared_ptr<QMessageBox> msgBox;

	std::shared_ptr<Car> car;
};

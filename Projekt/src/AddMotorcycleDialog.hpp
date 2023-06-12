#pragma once

#include "ui_AddMotorcycleDialog.h"

class QMessageBox;

class Motorcycle;

class AddMotorcycleDialog final : public QDialog
{
	Q_OBJECT

public:
	AddMotorcycleDialog(QWidget* parent = nullptr);
	~AddMotorcycleDialog() override = default;

	std::shared_ptr<Motorcycle> getMotorcycle() { return motorcycle; }

private slots:
	void finish();
	void cancel();

private:
	Ui::AddMotorcycleDialogClass ui;
	std::shared_ptr<QMessageBox> msgBox;

	std::shared_ptr<Motorcycle> motorcycle;
};

#pragma once

#include <QDialog>
#include <QMessageBox>

#include "ui_AddMotorcycleDialog.h"

class Motorcycle;

class AddMotorcycleDialog : public QDialog
{
	Q_OBJECT

public:
	AddMotorcycleDialog(QWidget *parent = nullptr);
	~AddMotorcycleDialog();

	std::shared_ptr<Motorcycle> getMotorcycle() { return motorcycle; }

private slots:
	void finish();
	void cancel();

private:
	Ui::AddMotorcycleDialogClass ui;
	std::shared_ptr<QMessageBox> msgBox;

	std::shared_ptr<Motorcycle> motorcycle;
};

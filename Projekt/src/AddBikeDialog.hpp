#pragma once

#include <QDialog>
#include <QMessageBox>

#include "ui_AddBikeDialog.h"

class Bike;

class AddBikeDialog : public QDialog
{
	Q_OBJECT

public:
	AddBikeDialog(QWidget *parent = nullptr);
	~AddBikeDialog();

	std::shared_ptr<Bike> getBike() const { return bike; }

private slots:
	void finish();
	void cancel();

private:
	Ui::AddBikeDialogClass ui;
	std::shared_ptr<QMessageBox> msgBox;

	std::shared_ptr<Bike> bike;
};

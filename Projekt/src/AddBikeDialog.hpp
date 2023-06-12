#pragma once

#include "ui_AddBikeDialog.h"

class QMessageBox;

class Bike;

class AddBikeDialog final : public QDialog
{
	Q_OBJECT

public:
	AddBikeDialog(QWidget* parent = nullptr);
	~AddBikeDialog() override = default;

	std::shared_ptr<Bike> getBike() const { return bike; }

private slots:
	void finish();
	void cancel();

private:
	Ui::AddBikeDialogClass ui;
	std::shared_ptr<QMessageBox> msgBox;

	std::shared_ptr<Bike> bike;
};

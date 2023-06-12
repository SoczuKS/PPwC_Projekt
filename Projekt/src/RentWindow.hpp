#pragma once

#include "ui_RentWindow.h"

class MainWindow;
class RentalService;
class Vehicle;
class User;

class RentWindow final : public QMainWindow
{
	Q_OBJECT

public:
	RentWindow(RentalService&, const std::shared_ptr<Vehicle>&, std::reference_wrapper<User>, MainWindow* = nullptr);
	~RentWindow() override = default;

private slots:
	void order();
	void timeChange(int) const;

private:
	Ui::RentWindowClass ui;
	RentalService& rentalService;
	std::reference_wrapper<User> user;
	std::shared_ptr<Vehicle> vehicle;
	MainWindow* mainWindow;
};

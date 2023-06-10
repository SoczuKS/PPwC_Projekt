#pragma once

#include <QMainWindow>

#include "ui_RentWindow.h"

class MainWindow;
class RentalService;
class Vehicle;
class User;

class RentWindow : public QMainWindow
{
	Q_OBJECT

public:
	RentWindow(RentalService& rentalService, std::shared_ptr<Vehicle> vehicle, std::reference_wrapper<User> user, MainWindow* parent = nullptr);
	~RentWindow();

private slots:
	void order();
	void timeChange(int);

private:
	Ui::RentWindowClass ui;
	RentalService& rentalService;
	std::reference_wrapper<User> user;
	std::shared_ptr<Vehicle> vehicle;
	MainWindow* mainWindow;
};

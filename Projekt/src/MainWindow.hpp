#pragma once

#include "ui_MainWindow.h"

#include "RentalService.hpp"
#include "User.hpp"
#include "VehicleDatabase.hpp"

class Logger;
class RentWindow;
class User;

class MainWindow final : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(std::reference_wrapper<User>, std::shared_ptr<Logger>, QWidget* = nullptr);
	~MainWindow() override = default;

	void orderDone();

private slots:
	void carSelected(int, int);
	void bikeSelected(int, int);
	void motorcycleSelected(int, int);
	void scooterSelected(int, int);

private:
	bool isAdmin() const { return User::Role::admin == user.get().getRole(); }

	void fillTables() const;
	void fillBikesTable() const;
	void fillCarsTable() const;
	void fillMotorcyclesTable() const;
	void fillScootersTable() const;
	void fillRentsTable() const;

	std::reference_wrapper<User> user;
	Ui::MainWindowClass ui;
	std::shared_ptr<Logger> logger;
	VehicleDatabase vehicleDatabase;
	RentalService rentalService;

	QTableWidget* bikesTable;
	QTableWidget* carsTable;
	QTableWidget* motorcyclesTable;
	QTableWidget* scootersTable;
	QTableWidget* rentsTable;

	std::shared_ptr<RentWindow> orderWindow;
};


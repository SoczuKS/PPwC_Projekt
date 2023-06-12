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
	MainWindow(std::reference_wrapper<User>, const std::shared_ptr<Logger>&, QWidget* = nullptr);
	~MainWindow() override = default;

	void orderDone() const;

private slots:
	void bikeSelected(int, int);
	void carSelected(int, int);
	void motorcycleSelected(int, int);
	void scooterSelected(int, int);

	void addBike();
	void addCar();
	void addMotorcycle();
	void addScooter();

private:
	bool isAdminLogged() const { return User::Role::admin == user.get().getRole(); }

	void setupUi();
	void setupAdministrativeUi();
	void changeAddButtonsState(bool) const;

	void fillTables() const;
	void fillBikesTable() const;
	void fillCarsTable() const;
	void fillMotorcyclesTable() const;
	void fillScootersTable() const;
	void fillRentsTable() const;

	void removeBike(int);
	void removeCar(int);
	void removeMotorcycle(int);
	void removeScooter(int);

	void resetBikesTable() const;
	void resetCarsTable() const;
	void resetMotorcyclesTable() const;
	void resetScootersTable() const;
	void resetRentsTable() const;

	bool confirmationDialog(const QString&, const QString&);

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

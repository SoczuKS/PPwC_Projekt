#include "MainWindow.hpp"

#include <QDateTime>

#include "Bike.hpp"
#include "Car.hpp"
#include "Motorcycle.hpp"
#include "Rent.hpp"
#include "Scooter.hpp"

MainWindow::MainWindow(const std::reference_wrapper<User> user, std::shared_ptr<Logger> logger, QWidget* parent) :
	QMainWindow(parent),
	user{ user },
	logger{ logger },
	vehicleDatabase{ VehicleDatabase(logger) },
	rentalService{ RentalService(logger) }
{
	ui.setupUi(this);

	carsTable = ui.carsTable;
	bikesTable = ui.bikesTable;
	motorcyclesTable = ui.motorcyclesTable;
	scootersTable = ui.scootersTable;
	rentsTable = ui.rentsTable;

	fillTables();
}

void MainWindow::fillTables() const
{
	fillBikesTable();
	fillCarsTable();
	fillMotorcyclesTable();
	fillScootersTable();
	fillRentsTable();
}

void MainWindow::fillBikesTable() const
{
	const auto& bikes = vehicleDatabase.getBikes();
	const auto bikesCount = bikes.size();

	bikesTable->setHorizontalHeaderLabels({ tr("Manufacturer"), tr("Model"), tr("Price per hour"), tr("Price per day") });

	bikesTable->setRowCount(bikesCount);
	bikesTable->setColumnCount(4);

	for (size_t i{ 0 }; i < bikesCount; ++i)
	{
		const auto& bike = bikes.at(i);
		bikesTable->setItem(i, 0, new QTableWidgetItem(bike->getManufacturer().c_str()));
		bikesTable->setItem(i, 1, new QTableWidgetItem(bike->getModel().c_str()));
		bikesTable->setItem(i, 2, new QTableWidgetItem(std::to_string(bike->getPricePerHour()).c_str()));
		bikesTable->setItem(i, 3, new QTableWidgetItem(std::to_string(bike->getPricePerDay()).c_str()));
	}
}

void MainWindow::fillCarsTable() const
{
	const auto& cars = vehicleDatabase.getCars();
	const auto carsCount = cars.size();

	carsTable->setHorizontalHeaderLabels({ tr("Manufacturer"), tr("Model"), tr("Price per hour"), tr("Price per day")});

	carsTable->setRowCount(carsCount);
	carsTable->setColumnCount(4);

	for (size_t i{ 0 }; i < carsCount; ++i)
	{
		const auto& car = cars.at(i);
		carsTable->setItem(i, 0, new QTableWidgetItem(car->getManufacturer().c_str()));
		carsTable->setItem(i, 1, new QTableWidgetItem(car->getModel().c_str()));
		carsTable->setItem(i, 2, new QTableWidgetItem(std::to_string(car->getPricePerHour()).c_str()));
		carsTable->setItem(i, 3, new QTableWidgetItem(std::to_string(car->getPricePerDay()).c_str()));
	}
}

void MainWindow::fillMotorcyclesTable() const
{
	const auto& motorcycles = vehicleDatabase.getMotorcycles();
	const auto motorcyclesCount = motorcycles.size();

	motorcyclesTable->setHorizontalHeaderLabels({ tr("Manufacturer"), tr("Model"), tr("Price per hour"), tr("Price per day") });

	motorcyclesTable->setRowCount(motorcyclesCount);
	motorcyclesTable->setColumnCount(4);

	for (size_t i{ 0 }; i < motorcyclesCount; ++i)
	{
		const auto& motorcycle = motorcycles.at(i);
		motorcyclesTable->setItem(i, 0, new QTableWidgetItem(motorcycle->getManufacturer().c_str()));
		motorcyclesTable->setItem(i, 1, new QTableWidgetItem(motorcycle->getModel().c_str()));
		motorcyclesTable->setItem(i, 2, new QTableWidgetItem(std::to_string(motorcycle->getPricePerHour()).c_str()));
		motorcyclesTable->setItem(i, 3, new QTableWidgetItem(std::to_string(motorcycle->getPricePerDay()).c_str()));
	}
}

void MainWindow::fillScootersTable() const
{
	const auto& scooters = vehicleDatabase.getScooters();
	const auto scootersCount = scooters.size();

	scootersTable->setHorizontalHeaderLabels({ tr("Manufacturer"), tr("Model"), tr("Price per hour"), tr("Price per day") });

	scootersTable->setRowCount(scootersCount);
	scootersTable->setColumnCount(4);

	for (size_t i{ 0 }; i < scootersCount; ++i)
	{
		const auto& scooter = scooters.at(i);
		scootersTable->setItem(i, 0, new QTableWidgetItem(scooter->getManufacturer().c_str()));
		scootersTable->setItem(i, 1, new QTableWidgetItem(scooter->getModel().c_str()));
		scootersTable->setItem(i, 2, new QTableWidgetItem(std::to_string(scooter->getPricePerHour()).c_str()));
		scootersTable->setItem(i, 3, new QTableWidgetItem(std::to_string(scooter->getPricePerDay()).c_str()));
	}
}

void MainWindow::fillRentsTable() const
{
	const auto& rents = rentalService.getRentsByUserId(user.get().getId());
	const auto rentsCount = rents.size();

	rentsTable->setHorizontalHeaderLabels({ tr("Vehicle"), tr("Start date"), tr("Days"), tr("Hours") });

	rentsTable->setRowCount(rentsCount);
	rentsTable->setColumnCount(4);

	for (size_t i{ 0 }; i < rentsCount; ++i)
	{
		const auto& rent = rents.at(i);
		const auto& vehicle = vehicleDatabase.getVehicleById(rent.get().getVehicleId());

		int unixTime = rent.get().getStartDate();
		QDateTime timestamp;
		timestamp.setSecsSinceEpoch(unixTime);
		
		rentsTable->setItem(i, 0, new QTableWidgetItem((vehicle->getManufacturer() + " " + vehicle->getModel()).c_str()));
		rentsTable->setItem(i, 1, new QTableWidgetItem(timestamp.toString()));
		rentsTable->setItem(i, 2, new QTableWidgetItem(std::to_string(rent.get().getDays()).c_str()));
		rentsTable->setItem(i, 3, new QTableWidgetItem(std::to_string(rent.get().getHours()).c_str()));
	}
}

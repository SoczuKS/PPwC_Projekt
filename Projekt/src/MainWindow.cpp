#include "MainWindow.hpp"

#include <QDateTime>
#include <QMessageBox>
#include <QTableWidget>

#include "AddBikeDialog.hpp"
#include "AddCarDialog.hpp"
#include "AddMotorcycleDialog.hpp"
#include "AddScooterDialog.hpp"
#include "Bike.hpp"
#include "Car.hpp"
#include "Motorcycle.hpp"
#include "Rent.hpp"
#include "RentWindow.hpp"
#include "Scooter.hpp"

namespace
{
const int& RemoveButtonColumnIndex = 4;
}

MainWindow::MainWindow(const std::reference_wrapper<User> user, std::shared_ptr<Logger> logger, QWidget* parent) :
	QMainWindow(parent),
	user{ user },
	logger{ logger },
	vehicleDatabase{ VehicleDatabase(logger) },
	rentalService{ RentalService(logger) }
{
	ui.setupUi(this);

	setupUi();
}

void MainWindow::setupUi()
{
	carsTable = ui.carsTable;
	bikesTable = ui.bikesTable;
	motorcyclesTable = ui.motorcyclesTable;
	scootersTable = ui.scootersTable;
	rentsTable = ui.rentsTable;

	connect(bikesTable, &QTableWidget::cellClicked, this, &MainWindow::bikeSelected);
	connect(carsTable, &QTableWidget::cellClicked, this, &MainWindow::carSelected);
	connect(motorcyclesTable, &QTableWidget::cellClicked, this, &MainWindow::motorcycleSelected);
	connect(scootersTable, &QTableWidget::cellClicked, this, &MainWindow::scooterSelected);

	fillTables();

	setupAdministrativeUi();
	changeAddButtonsState(isAdminLogged());
}

void MainWindow::setupAdministrativeUi()
{
	if (not isAdminLogged())
	{
		return;
	}

	connect(ui.addBikeButton, &QPushButton::released, this, &MainWindow::addBike);
	connect(ui.addCarButton, &QPushButton::released, this, &MainWindow::addCar);
	connect(ui.addMotorcycleButton, &QPushButton::released, this, &MainWindow::addMotorcycle);
	connect(ui.addScooterButton, &QPushButton::released, this, &MainWindow::addScooter);
}

void MainWindow::changeAddButtonsState(bool enabled)
{
	ui.addBikeButton->setEnabled(enabled);
	ui.addBikeButton->setVisible(enabled);

	ui.addCarButton->setEnabled(enabled);
	ui.addCarButton->setVisible(enabled);

	ui.addMotorcycleButton->setEnabled(enabled);
	ui.addMotorcycleButton->setVisible(enabled);

	ui.addScooterButton->setEnabled(enabled);
	ui.addScooterButton->setVisible(enabled);
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

	QStringList headers{ tr("manufacturer"), tr("model"), tr("price_per_hour"), tr("price_per_day") };
	if (isAdminLogged())
	{
		headers << tr("remove");
		bikesTable->setColumnCount(RemoveButtonColumnIndex + 1);
	}

	bikesTable->setRowCount(bikesCount);

	for (size_t i{ 0 }; i < bikesCount; ++i)
	{
		const auto& bike = bikes.at(i);
		bikesTable->setItem(i, 0, new QTableWidgetItem(bike->getManufacturer().c_str()));
		bikesTable->setItem(i, 1, new QTableWidgetItem(bike->getModel().c_str()));
		bikesTable->setItem(i, 2, new QTableWidgetItem(QString::number(bike->getPricePerHour())));
		bikesTable->setItem(i, 3, new QTableWidgetItem(QString::number(bike->getPricePerDay())));
		if (isAdminLogged())
		{
			auto item = new QTableWidgetItem(tr("remove"));
			item->setForeground(QColor(255, 0, 0));
			bikesTable->setItem(i, 4, item);
		}
	}

	bikesTable->setHorizontalHeaderLabels(headers);
}

void MainWindow::fillCarsTable() const
{
	const auto& cars = vehicleDatabase.getCars();
	const auto carsCount = cars.size();

	QStringList headers{ tr("manufacturer"), tr("model"), tr("price_per_hour"), tr("price_per_day") };
	if (isAdminLogged())
	{
		headers << tr("remove");
		carsTable->setColumnCount(RemoveButtonColumnIndex + 1);
	}

	carsTable->setRowCount(carsCount);

	for (size_t i{ 0 }; i < carsCount; ++i)
	{
		const auto& car = cars.at(i);
		carsTable->setItem(i, 0, new QTableWidgetItem(car->getManufacturer().c_str()));
		carsTable->setItem(i, 1, new QTableWidgetItem(car->getModel().c_str()));
		carsTable->setItem(i, 2, new QTableWidgetItem(QString::number(car->getPricePerHour())));
		carsTable->setItem(i, 3, new QTableWidgetItem(QString::number(car->getPricePerDay())));
		if (isAdminLogged())
		{
			auto item = new QTableWidgetItem(tr("remove"));
			item->setForeground(QColor(255, 0, 0));
			carsTable->setItem(i, 4, item);
		}
	}

	carsTable->setHorizontalHeaderLabels(headers);
}

void MainWindow::fillMotorcyclesTable() const
{
	const auto& motorcycles = vehicleDatabase.getMotorcycles();
	const auto motorcyclesCount = motorcycles.size();

	QStringList headers{ tr("manufacturer"), tr("model"), tr("price_per_hour"), tr("price_per_day") };
	if (isAdminLogged())
	{
		headers << tr("remove");
		motorcyclesTable->setColumnCount(RemoveButtonColumnIndex + 1);
	}

	motorcyclesTable->setRowCount(motorcyclesCount);

	for (size_t i{ 0 }; i < motorcyclesCount; ++i)
	{
		const auto& motorcycle = motorcycles.at(i);
		motorcyclesTable->setItem(i, 0, new QTableWidgetItem(motorcycle->getManufacturer().c_str()));
		motorcyclesTable->setItem(i, 1, new QTableWidgetItem(motorcycle->getModel().c_str()));
		motorcyclesTable->setItem(i, 2, new QTableWidgetItem(QString::number(motorcycle->getPricePerHour())));
		motorcyclesTable->setItem(i, 3, new QTableWidgetItem(QString::number(motorcycle->getPricePerDay())));
		if (isAdminLogged())
		{
			auto item = new QTableWidgetItem(tr("remove"));
			item->setForeground(QColor(255, 0, 0));
			motorcyclesTable->setItem(i, 4, item);
		}
	}

	motorcyclesTable->setHorizontalHeaderLabels(headers);
}

void MainWindow::fillScootersTable() const
{
	const auto& scooters = vehicleDatabase.getScooters();
	const auto scootersCount = scooters.size();

	QStringList headers{ tr("manufacturer"), tr("model"), tr("price_per_hour"), tr("price_per_day") };
	if (isAdminLogged())
	{
		headers << tr("remove");
		scootersTable->setColumnCount(RemoveButtonColumnIndex + 1);
	}

	scootersTable->setRowCount(scootersCount);

	for (size_t i{ 0 }; i < scootersCount; ++i)
	{
		const auto& scooter = scooters.at(i);
		scootersTable->setItem(i, 0, new QTableWidgetItem(scooter->getManufacturer().c_str()));
		scootersTable->setItem(i, 1, new QTableWidgetItem(scooter->getModel().c_str()));
		scootersTable->setItem(i, 2, new QTableWidgetItem(QString::number(scooter->getPricePerHour())));
		scootersTable->setItem(i, 3, new QTableWidgetItem(QString::number(scooter->getPricePerDay())));
		if (isAdminLogged())
		{
			auto item = new QTableWidgetItem(tr("remove"));
			item->setForeground(QColor(255, 0, 0));
			scootersTable->setItem(i, 4, item);
		}
	}

	scootersTable->setHorizontalHeaderLabels(headers);
}

void MainWindow::fillRentsTable() const
{
	const auto& rents = rentalService.getRentsByUserId(user.get().getId());
	const auto rentsCount = rents.size();

	rentsTable->setRowCount(rentsCount);

	QDateTime timestamp;

	for (size_t i{ 0 }; i < rentsCount; ++i)
	{
		const auto& rent = rents.at(i);
		const auto& vehicle = vehicleDatabase.getVehicleById(rent.get().getVehicleId());

		timestamp.setSecsSinceEpoch(rent.get().getStartDate());

		rentsTable->setItem(i, 0, new QTableWidgetItem((vehicle->getManufacturer() + " " + vehicle->getModel()).c_str()));
		rentsTable->setItem(i, 1, new QTableWidgetItem(timestamp.toString(QLocale::system().dateTimeFormat())));
		rentsTable->setItem(i, 2, new QTableWidgetItem(std::to_string(rent.get().getDays()).c_str()));
		rentsTable->setItem(i, 3, new QTableWidgetItem(std::to_string(rent.get().getHours()).c_str()));
	}

	QStringList headers{ tr("vehicle"), tr("start_date"), tr("days"), tr("hours") };

	rentsTable->setHorizontalHeaderLabels(headers);
}

void MainWindow::bikeSelected(int row, int column)
{
	if (RemoveButtonColumnIndex == column)
	{
		removeBike(row);
		return;
	}

	const auto& bike = vehicleDatabase.getBikes().at(row);

	orderWindow = std::make_unique<RentWindow>(rentalService, bike, user, this);
	orderWindow->show();
}

void MainWindow::carSelected(int row, int column)
{
	if (RemoveButtonColumnIndex == column)
	{
		removeCar(row);
		return;
	}

	const auto& car = vehicleDatabase.getCars().at(row);

	orderWindow = std::make_unique<RentWindow>(rentalService, car, user, this);
	orderWindow->show();
}

void MainWindow::motorcycleSelected(int row, int column)
{
	if (RemoveButtonColumnIndex == column)
	{
		removeMotorcycle(row);
		return;
	}

	const auto& motorcycle = vehicleDatabase.getMotorcycles().at(row);

	orderWindow = std::make_unique<RentWindow>(rentalService, motorcycle, user, this);
	orderWindow->show();
}

void MainWindow::scooterSelected(int row, int column)
{
	if (RemoveButtonColumnIndex == column)
	{
		removeScooter(row);
		return;
	}

	const auto& scooter = vehicleDatabase.getScooters().at(row);

	orderWindow = std::make_unique<RentWindow>(rentalService, scooter, user, this);
	orderWindow->show();
}

void MainWindow::orderDone()
{
	resetRentsTable();
}

void MainWindow::removeBike(int index)
{
	if (not isAdminLogged())
	{
		return;
	}

	if (not confirmationDialog(tr("bike_remove_title"), tr("bike_remove_question")))
	{
		return;
	}

	const auto& bike = vehicleDatabase.getBikes().at(index);

	vehicleDatabase.removeVehicle(bike->getId());

	resetBikesTable();
}

void MainWindow::removeCar(int index)
{
	if (not isAdminLogged())
	{
		return;
	}

	if (not confirmationDialog(tr("car_remove_title"), tr("car_remove_question")))
	{
		return;
	}

	const auto& car = vehicleDatabase.getCars().at(index);

	vehicleDatabase.removeVehicle(car->getId());

	resetCarsTable();
}

void MainWindow::removeMotorcycle(int index)
{
	if (not isAdminLogged())
	{
		return;
	}

	if (not confirmationDialog(tr("motorcycle_remove_title"), tr("motorcycle_remove_question")))
	{
		return;
	}

	const auto& motorcycle = vehicleDatabase.getMotorcycles().at(index);

	vehicleDatabase.removeVehicle(motorcycle->getId());

	resetMotorcyclesTable();
}

void MainWindow::removeScooter(int index)
{
	if (not isAdminLogged())
	{
		return;
	}

	if (not confirmationDialog(tr("scooter_remove_title"), tr("scooter_remove_question")))
	{
		return;
	}

	const auto& scooter = vehicleDatabase.getScooters().at(index);

	vehicleDatabase.removeVehicle(scooter->getId());

	resetScootersTable();
}

bool MainWindow::confirmationDialog(const QString& title, const QString& text)
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, title, text,
								  QMessageBox::Yes | QMessageBox::No);
	return reply == QMessageBox::Yes;
}

void MainWindow::resetBikesTable()
{
	bikesTable->clear();
	fillBikesTable();
}

void MainWindow::resetCarsTable()
{
	carsTable->clear();
	fillCarsTable();
}

void MainWindow::resetMotorcyclesTable()
{
	motorcyclesTable->clear();
	fillMotorcyclesTable();
}

void MainWindow::resetScootersTable()
{
	scootersTable->clear();
	fillScootersTable();
}

void MainWindow::resetRentsTable()
{
	rentsTable->clear();
	fillRentsTable();
}

void MainWindow::addBike()
{
	AddBikeDialog dialog(this);
	dialog.setModal(true);

	if (dialog.exec() == QDialog::Accepted)
	{
		vehicleDatabase.addVehicle(dialog.getBike());
		resetBikesTable();
	}
}

void MainWindow::addCar()
{
	AddCarDialog dialog(this);
	dialog.setModal(true);

	if (dialog.exec() == QDialog::Accepted)
	{
		vehicleDatabase.addVehicle(dialog.getCar());
		resetCarsTable();
	}
}

void MainWindow::addMotorcycle()
{
	AddMotorcycleDialog dialog(this);
	dialog.setModal(true);

	if (dialog.exec() == QDialog::Accepted)
	{
		vehicleDatabase.addVehicle(dialog.getMotorcycle());
		resetMotorcyclesTable();
	}
}

void MainWindow::addScooter()
{
	AddScooterDialog dialog(this);
	dialog.setModal(true);

	if (dialog.exec() == QDialog::Accepted)
	{
		vehicleDatabase.addVehicle(dialog.getScooter());
		resetScootersTable();
	}
}

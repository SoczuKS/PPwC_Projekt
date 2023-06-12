#include "RentWindow.hpp"

#include "MainWindow.hpp"
#include "RentalService.hpp"
#include "User.hpp"
#include "Vehicle.hpp"

RentWindow::RentWindow(RentalService& rentalService, const std::shared_ptr<Vehicle>& vehicle, const std::reference_wrapper<User> user, MainWindow* mainWindow) :
	QMainWindow(mainWindow),
	rentalService{ rentalService },
	user{ user },
	vehicle{ vehicle },
	mainWindow{ mainWindow }
{
	ui.setupUi(this);

	ui.vehicleDescriptionText->setText(vehicle->getDescription().c_str());
	ui.pricePerHour->setPlainText(std::to_string(vehicle->getPricePerHour()).c_str());
	ui.pricePerDay->setPlainText(std::to_string(vehicle->getPricePerDay()).c_str());

	connect(ui.orderButton, &QPushButton::pressed, this, &RentWindow::order);
	connect(ui.hoursSelector, &QSpinBox::valueChanged, this, &RentWindow::timeChange);
	connect(ui.daysSelector, &QSpinBox::valueChanged, this, &RentWindow::timeChange);
}

void RentWindow::order()
{
	const auto hours = ui.hoursSelector->value();
	const auto days = ui.daysSelector->value();

	rentalService.rentVehicle(user.get().getId(), vehicle->getId(), hours, days);

	mainWindow->orderDone();

	close();
}

void RentWindow::timeChange(int) const
{
	if (ui.hoursSelector->value() >= 24)
	{
		ui.hoursSelector->setValue(0);
		ui.daysSelector->setValue(ui.daysSelector->value() + 1);
	}

	const auto days = ui.daysSelector->value();
	const auto hours = ui.hoursSelector->value();

	ui.priceTextView->setPlainText(std::to_string(days * vehicle->getPricePerDay() + hours * vehicle->getPricePerHour()).c_str());
}

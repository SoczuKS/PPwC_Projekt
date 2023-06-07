#include "MainWindow.hpp"

MainWindow::MainWindow(const std::reference_wrapper<User> user, std::shared_ptr<Logger> logger, QWidget* parent) : 
	QMainWindow(parent),
	user{ user },
	logger{ logger },
	vehicleDatabase{ VehicleDatabase(logger) },
	rentalService{ RentalService(logger) }
{
	ui.setupUi(this);
}
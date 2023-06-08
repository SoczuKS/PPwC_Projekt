#pragma once

#include "ui_MainWindow.h"

#include "RentalService.hpp"
#include "User.hpp"
#include "VehicleDatabase.hpp"

class Logger;
class User;

class MainWindow final : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(std::reference_wrapper<User>, std::shared_ptr<Logger>, QWidget* = nullptr);
	~MainWindow() override = default;

private slots:

private:
	bool isAdmin() const { return User::Role::admin == user.get().getRole(); }

	std::reference_wrapper<User> user;
	Ui::MainWindowClass ui;
	std::shared_ptr<Logger> logger;
	VehicleDatabase vehicleDatabase;
	RentalService rentalService;
};


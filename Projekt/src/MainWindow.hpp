#pragma once

#include "ui_MainWindow.h"

#include "RentalService.hpp"
#include "User.hpp"
#include "VehicleDatabase.hpp"

class User;

class MainWindow final : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(std::reference_wrapper<User>, QWidget* = nullptr);
	~MainWindow() override = default;

private slots:

private:
	std::reference_wrapper<User> user;
	Ui::MainWindowClass ui;
	VehicleDatabase vehicleDatabase;
	RentalService rentalService;
	bool isAdmin() const { return User::Role::admin == user.get().getRole(); }
};


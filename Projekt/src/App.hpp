#pragma once

#include "ui_App.h"

#include "UserManager.hpp"
#include "VehicleDatabase.hpp"

class App final : public QMainWindow
{
	Q_OBJECT

public:
	App(QWidget* parent = nullptr);
	~App() override = default;

private slots:
	void login();
	void registration();

private:
	enum class LoginAndRegistrationError { emptyField, invalidCredentials, usernameTaken };

	Ui::AppClass ui;
	UserManager userManager;
	VehicleDatabase vehicleDatabase;

	void loginAndRegistrationErrorHandler(LoginAndRegistrationError);
	void loginAndRegistrationSuccessHandler(std::reference_wrapper<User>);
};

#pragma once

#include "ui_App.h"

#include "MainWindow.hpp"
#include "UserManager.hpp"
#include "VehicleDatabase.hpp"

class Logger;

class App final : public QMainWindow
{
	Q_OBJECT

public:
	App(std::shared_ptr<Logger>, QWidget* = nullptr);
	~App() override = default;

private slots:
	void login();
	void registration();

private:
	enum class LoginAndRegistrationError { emptyField, invalidCredentials, usernameTaken };

	void loginAndRegistrationErrorHandler(LoginAndRegistrationError);
	void loginAndRegistrationSuccessHandler(std::reference_wrapper<User>);

	Ui::AppClass ui;
	std::unique_ptr<MainWindow> mainWindow;
	std::shared_ptr<Logger> logger;
	UserManager userManager;
};

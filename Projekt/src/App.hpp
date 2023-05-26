#pragma once

#include "ui_App.h"

#include "MainWindow.hpp"
#include "UserManager.hpp"
#include "VehicleDatabase.hpp"

class App final : public QMainWindow
{
	Q_OBJECT

public:
	App(QWidget* = nullptr);
	~App() override = default;

private slots:
	void login();
	void registration();

private:
	enum class LoginAndRegistrationError { emptyField, invalidCredentials, usernameTaken };

	Ui::AppClass ui;
	UserManager userManager;
	std::unique_ptr<MainWindow> mainWindow;

	void loginAndRegistrationErrorHandler(LoginAndRegistrationError);
	void loginAndRegistrationSuccessHandler(std::reference_wrapper<User>);
};

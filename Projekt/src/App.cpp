#include "App.hpp"

#include "User.hpp"

App::App(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.loginButton, &QPushButton::pressed, this, &App::login);
	connect(ui.registerButton, &QPushButton::pressed, this, &App::registration);
}

void App::login()
{
	const auto loginText = ui.loginTextEdit->text();
	const auto passwordText = ui.passwordTextEdit->text();

	if (loginText.isEmpty() or passwordText.isEmpty())
	{
		loginAndRegistrationErrorHandler(LoginAndRegistrationError::emptyField);
		return;
	}

	auto user = userManager.login(loginText.toStdString(), passwordText.toStdString());

	if (not user)
	{
		loginAndRegistrationErrorHandler(LoginAndRegistrationError::invalidCredentials);
		return;
	}

	loginAndRegistrationSuccessHandler(user.value());
}

void App::registration()
{
	const auto loginText = ui.loginTextEdit->text();
	const auto passwordText = ui.passwordTextEdit->text();

	if (loginText.isEmpty() or passwordText.isEmpty())
	{
		loginAndRegistrationErrorHandler(LoginAndRegistrationError::emptyField);
		return;
	}

	auto user = userManager.registration(loginText.toStdString(), passwordText.toStdString());

	if (not user)
	{
		loginAndRegistrationErrorHandler(LoginAndRegistrationError::usernameTaken);
		return;
	}

	loginAndRegistrationSuccessHandler(user.value());
}

void App::loginAndRegistrationErrorHandler(LoginAndRegistrationError err)
{
	ui.errorTextView->setEnabled(true);

	switch (err)
	{
	case LoginAndRegistrationError::emptyField:
		ui.errorTextView->setPlainText(tr("empty_field"));
		break;

	case LoginAndRegistrationError::invalidCredentials:
		ui.errorTextView->setPlainText(tr("invalid_credentials"));
		break;

	case LoginAndRegistrationError::usernameTaken:
		ui.errorTextView->setPlainText(tr("username_taken"));
		break;

	default:
		ui.errorTextView->setPlainText(tr("unknown_error"));
	}
}

void App::loginAndRegistrationSuccessHandler(std::reference_wrapper<User> user)
{
	mainWindow = std::make_unique<MainWindow>(user);
	mainWindow->show();
	close();
}

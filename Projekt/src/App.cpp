#include "App.hpp"

#include "Logger.hpp"
#include "User.hpp"

App::App(const std::shared_ptr<Logger>& logger, QWidget* parent) : QMainWindow(parent), logger{ logger }, userManager{ UserManager(logger) }
{
	ui.setupUi(this);

	connect(ui.loginButton, &QPushButton::pressed, this, &App::login);
	connect(ui.registerButton, &QPushButton::pressed, this, &App::registration);

	logger->write("App started");

#ifdef LOGIN_AS_ADMIN
	ui.loginTextEdit->setText("admin");
	ui.passwordTextEdit->setText("admin123");
	login();
#endif
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

	const auto user = userManager.login(loginText.toStdString(), passwordText.toStdString());

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

	const auto user = userManager.registration(loginText.toStdString(), passwordText.toStdString());

	if (not user)
	{
		loginAndRegistrationErrorHandler(LoginAndRegistrationError::usernameTaken);
		return;
	}

	loginAndRegistrationSuccessHandler(user.value());
}

void App::loginAndRegistrationErrorHandler(const LoginAndRegistrationError err) const
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
	mainWindow = std::make_unique<MainWindow>(user, logger);
	mainWindow->show();
	close();
}

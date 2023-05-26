#include "MainWindow.hpp"

MainWindow::MainWindow(std::reference_wrapper<User> user, QWidget* parent) : QMainWindow(parent), user{ user }
{
	ui.setupUi(this);
}
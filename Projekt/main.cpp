#include "App.hpp"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	App app;
	app.show();
	return a.exec();
}

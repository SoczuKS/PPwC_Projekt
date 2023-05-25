#include <QtWidgets/QApplication>
#include <QLocale>
#include <QTranslator>

#include "App.hpp"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QTranslator translator;
	if (translator.load("locale_" + QLocale::system().name()))
	{
		a.installTranslator(&translator);
	}

	App app;
	app.show();
	return a.exec();
}

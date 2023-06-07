#include <QtWidgets/QApplication>
#include <QLocale>
#include <QTranslator>

#include "App.hpp"
#include "Logger.hpp"

int main(int argc, char* argv[])
{
	auto logger = std::make_shared<Logger>();
	logger->write("App starting...");
	QApplication a(argc, argv);

	QTranslator translator;
	if (translator.load("locale_" + QLocale::system().name()))
	{
		a.installTranslator(&translator);
	}

	App app(logger);
	app.show();
	return a.exec();
}

#include <QTranslator>

#include "App.hpp"
#include "Logger.hpp"

int main(int argc, char* argv[])
{
	const auto logger = std::make_shared<Logger>();
	logger->write("App starting...");
	QApplication a(argc, argv);

	QTranslator translator;
	if (translator.load("locale_" + QLocale::system().name()))
	{
		a.installTranslator(&translator);
	}

	App app(logger);
	app.show();

	const auto appResult = a.exec();
	logger->write("App finished with status" + std::to_string(appResult));
	return appResult;
}

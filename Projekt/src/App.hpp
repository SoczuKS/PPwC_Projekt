#pragma once

#include "ui_App.h"

#include "UserManager.hpp"

class App final : public QMainWindow
{
	Q_OBJECT

public:
	App(QWidget* parent = nullptr);
	~App() override = default;

private:
	Ui::AppClass ui;
	UserManager userManager;
};

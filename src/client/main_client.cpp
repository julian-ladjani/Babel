#include <iostream>

#include <QtWidgets>
#include <src/client/windows/Window.hpp>
#include "QPalette"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	babel::client::MainWindow w;
	w.show();

	return a.exec();
}
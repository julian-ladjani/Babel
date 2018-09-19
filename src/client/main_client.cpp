#include <iostream>
#include <src/client/windows/Window.hpp>
#include <QtGui/QPalette>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	babel::client::MainWindow w;
	w.show();

	return a.exec();
}
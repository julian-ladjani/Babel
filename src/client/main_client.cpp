#include <iostream>
#include <QtGui>
#include <QtWidgets>
#include <QPalette>
#include <QApplication>
#include "./windows/Window.hpp"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	babel::client::MainWindow w;
	w.show();

	return a.exec();
}
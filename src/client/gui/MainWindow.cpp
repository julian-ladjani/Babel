//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// MainWindow.cpp
//

#include "MainWindow.hpp"
#include "src/client/gui/pages/ConnectionPage.hpp"

babel::client::MainWindow::MainWindow() : _cnxPage(new ConnectionPage(_infos))
{
	resize(1280, 720);
	setWindowTitle(QApplication::translate(
		"Epyks", "Epyks, Grand et impuissant !"));
	setStyleSheet("background-color:#3d3d3d");
	_pages.addWidget(_cnxPage.get());
	setCentralWidget(&_pages);
}
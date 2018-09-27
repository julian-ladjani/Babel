//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// MainWindow.cpp
//

#include "MainWindow.hpp"

babel::client::MainWindow::MainWindow()
{
	resize(1280, 720);
	setWindowTitle(QApplication::translate(
		"Epyks", "Epyks, Grand et impuissant !"));
	setStyleSheet("background-color:#3d3d3d");
	_pages.addWidget(new ConnectionPage(_infos), "connection");
	_pages.addWidget(new MainPage(_infos), "main");
	setCentralWidget(&_pages);
	connect((ConnectionPage *)_pages.getPage("connection"),
		&ConnectionPage::askForConnection,
		this, &MainWindow::yoloTest);
}

void babel::client::MainWindow::yoloTest()
{
	printf("Julian le gros pd !\n");
}
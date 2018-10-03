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
	srand(static_cast<unsigned int>(time(nullptr)));
	setWindowTitle(QApplication::translate(
		"Epyks", "Epyks, Grand et impuissant !"));
	setStyleSheet("background-color:#3d3d3d");
	initClientInfos();
	_pages.addWidget(new ConnectionPage(_infos), "connection");
	_pages.addWidget(new MainPage(_infos), "main");
	_pages.addWidget(new EchoSoundTestServicePage(_infos),
			 "echo_sound_test_service");
	setCentralWidget(&_pages);
	connect((ConnectionPage *)_pages.getPage("connection"),
		&ConnectionPage::changePage, this, &MainWindow::changePage);
	QApplication::setWindowIcon(QIcon("src/assets/img/minilogo.png"));
    	QFontDatabase::removeAllApplicationFonts();
	QFontDatabase::addApplicationFont("src/assets/font/DejaVuSans.ttf");
}

void babel::client::MainWindow::initClientInfos()
{
	babel::common::User user;
	babel::common::ConnectionInfo cinfo;
	foreach (const QHostAddress &addr, QNetworkInterface::allAddresses()) {
		if (addr.protocol() == QAbstractSocket::IPv4Protocol &&
			addr != QHostAddress(QHostAddress::LocalHost))
			cinfo.setIp(addr.toString().toStdString());
	}
	user.setConnectionInfo(cinfo);
	_infos.setClientInfo(user);
}

void babel::client::MainWindow::changePage(std::string pageName)
{
	std::cout << _infos.getClientInfo().getLogin() << std::endl;
	std::cout << pageName << std::endl;
        if (pageName == "main") {
	    MainPage *mainPage = (MainPage *) _pages.getPage(pageName);
	    mainPage->setLogin();
	}
	_pages.setCurrentPage(pageName);
}
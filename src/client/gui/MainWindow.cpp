//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// MainWindow.cpp
//

#include <src/common/command/CommandLogout.hpp>
#include "MainWindow.hpp"

babel::client::MainWindow::MainWindow() : _cmdHandler(_infos)
{
	resize(1280, 720);
	setWindowTitle(QApplication::translate(
		"Epyks", "Epyks, Grand et impuissant !"));
	setStyleSheet("background-color:#3d3d3d; color:#3d3d3d;");
	initClientInfos();
	_pages.addWidget(new ConnectionPage(_infos), "connection");
	_pages.addWidget(new MainPage(_infos), "main");
	setCentralWidget(&_pages);
	QApplication::setWindowIcon(QIcon("src/assets/img/minilogo.png"));
    	QFontDatabase::removeAllApplicationFonts();
	QFontDatabase::addApplicationFont("src/assets/font/DejaVuSans.ttf");
	initConnects();
}

void babel::client::MainWindow::initConnects()
{
	auto mainPage = (MainPage *)_pages.getPage("main");
	connect(mainPage, &MainPage::disconnect, this, &MainWindow::disconnect);
	connect((ConnectionPage *)_pages.getPage("connection"),
		&ConnectionPage::changePage, this, &MainWindow::tryConnect);
	connect(&_infos.getSocket(), &QtTcpSocket::connectionSuccess,
		this, &MainWindow::login);
	connect(&mainPage->getCallSection(), &CallPage::sendMessageSignal,
		this, &MainWindow::sendMessage);
}

void babel::client::MainWindow::sendMessage(std::string &msg)
{
	_infos.getSocket().send(common::CommandMessage(
			{std::to_string(_infos.getActiveUser().getId()),
			 msg}).serialize());
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

void babel::client::MainWindow::tryConnect()
{
	if (!_infos.getSocket().connect())
		return;
}

void babel::client::MainWindow::disconnect()
{
	_infos.getSocket().send(common::CommandLogout({}).serialize());
	_infos.getSocket().disconnect();
	changePage("connection");
}

void babel::client::MainWindow::login()
{
	common::CommandLogin cmd(
		{_infos.getClientInfo().getLogin(),
		 _infos.getClientInfo().getPassword()});
	_infos.getSocket().send(cmd.serialize());
	changePage("main");
}

void babel::client::MainWindow::changePage(std::string pageName)
{
        if (pageName == "main") {
	    MainPage *mainPage = (MainPage *) _pages.getPage(pageName);
	    mainPage->setLogin();
	}
	_pages.setCurrentPage(pageName);
}
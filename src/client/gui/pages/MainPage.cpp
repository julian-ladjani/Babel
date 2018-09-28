//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// MainPage.cpp
//

#include "MainPage.hpp"

babel::client::MainPage::MainPage(babel::client::ClientInfo &_infos) :
	_udpSocket(this),
	_sender(new Button("SEND", STYLEDEFBUTTON, Size(500, 30))),
	ABabelPage(_infos)
{
	initSocket();
	connections();
}

void babel::client::MainPage::initSocket()
{
	_sender = new Button("SEND", STYLEDEFBUTTON, Size(500, 30));
	auto addr = _infos.getClientInfo().getConnectionInfo().getIp();
	QHostAddress address(QString::fromStdString(addr));
	_udpSocket.bind(address);
	_layout->addWidget(_sender, 0, 0, 3, 2);
	_layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	setLayout(_layout);
}

void babel::client::MainPage::connections()
{
	connect(&_udpSocket, &QUdpSocket::readyRead, this, &MainPage::readData);
	connect(_sender, &Button::clicked, this, &MainPage::sendData);
}

void babel::client::MainPage::readData()
{
	while (_udpSocket.hasPendingDatagrams()) {
		QNetworkDatagram datagram = _udpSocket.receiveDatagram();
		std::cout << datagram.data().toStdString() << std::endl;
	}
}

void babel::client::MainPage::sendData()
{
	_udpSocket.writeDatagram
		(QByteArray("coucou"), QHostAddress::LocalHost, 7777);
}
//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// MainPage.cpp
//

#include <src/client/gui/components/Button.hpp>
#include "MainPage.hpp"
#include "ConnectionPage.hpp"

babel::client::MainPage::MainPage(babel::client::ClientInfo &_infos)
	: _udpSocket(this), ABabelPage(_infos)
{
	initSocket();
}

void babel::client::MainPage::initSocket()
{
	printf("dede\n");
	_udpSocket.bind(QHostAddress::LocalHost, 7777);
	printf("dede\n");
	Button *sender = new Button("SEND", STYLEDEFBUTTON, Size(500, 30));
	_layout->addWidget(sender, 0, 0, 3, 2);
	_layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	setLayout(_layout);
	connect(&_udpSocket, &QUdpSocket::readyRead,
		this, &MainPage::readPendingDatagrams);
	connect(sender, &Button::clicked,
		this, &MainPage::sendDatagrams);
}

void babel::client::MainPage::readPendingDatagrams()
{
	while (_udpSocket.hasPendingDatagrams()) {
		QNetworkDatagram datagram = _udpSocket.receiveDatagram();
		std::cout << datagram.data().toStdString() << std::endl;
	}
}

void babel::client::MainPage::sendDatagrams()
{
	const QByteArray &datagram("Coucou");
	_udpSocket.writeDatagram(datagram, QHostAddress::LocalHost, 7755);
}
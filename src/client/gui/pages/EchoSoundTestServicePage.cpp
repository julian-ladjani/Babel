//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// EchoSoundTestServicePage.cpp
//

#include "EchoSoundTestServicePage.hpp"

babel::client::EchoSoundTestServicePage::EchoSoundTestServicePage
	(babel::client::ClientInfo &_infos) :
	_udpSocket(this),
	_sender(new Button("SEND", STYLEDEFBUTTON, Size(500, 30))),
	ABabelPage(_infos)
{
	initSocket();
	connections();
}

void babel::client::EchoSoundTestServicePage::initSocket()
{
	_sender = new Button("SEND", STYLEDEFBUTTON, Size(500, 30));
	auto addr = _infos.getClientInfo().getConnectionInfo().getIp();
	QHostAddress address(QString::fromStdString(addr));
	_udpSocket.bind(address, 7777);
	qDebug() << _udpSocket.localAddress().toString() << ":"
		 << _udpSocket.localPort();
	_layout->addWidget(_sender, 0, 0, 3, 2);
	_layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	setLayout(_layout);
}

void babel::client::EchoSoundTestServicePage::connections()
{
	connect(&_udpSocket, &QUdpSocket::readyRead, this, &EchoSoundTestServicePage::readData);
	connect(_sender, &Button::clicked, this, &EchoSoundTestServicePage::sendData);
}

void babel::client::EchoSoundTestServicePage::readData()
{
	while (_udpSocket.hasPendingDatagrams()) {
		QNetworkDatagram datagram = _udpSocket.receiveDatagram();
		std::cout << datagram.data().toStdString() << std::endl;
	}
}

void babel::client::EchoSoundTestServicePage::sendData()
{
	_udpSocket.writeDatagram
		(QByteArray("coucou"), QHostAddress::LocalHost, 7777);
}
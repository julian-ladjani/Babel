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
	_buttons{std::make_unique<Button>("SEND", STYLEDEFBUTTON, Size(500, 30))},
	_inputs{std::make_unique<Input>(240, "Ip Address"),
	        std::make_unique<Input>(240, "Port"),
		std::make_unique<Input>(500, "Message")}, ABabelPage(_infos)
{
	_layout->addWidget(_inputs.at(IP_ADDRESS).get(), 0, 0, 1, 1);
	_layout->addWidget(_inputs.at(PORT).get(), 0, 1, 1, 1);
	_layout->addWidget(_inputs.at(MSG).get(), 1, 0, 1, 2);
	_layout->addWidget(_buttons.at(SEND).get(), 2, 0, 1, 2);
	_layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	initSocket();
	connections();
}

void babel::client::EchoSoundTestServicePage::initSocket()
{
	auto addr = _infos.getClientInfo().getConnectionInfo().getIp();
	QHostAddress address(QString::fromStdString(addr));
	_udpSocket.bind(address);
	printf("couille\n");
	qDebug() << _udpSocket.localAddress().toString() << ":"
		 << _udpSocket.localPort();
}

void babel::client::EchoSoundTestServicePage::connections()
{
	connect(&_udpSocket, &QUdpSocket::readyRead, this, &EchoSoundTestServicePage::readData);
	connect(_buttons.at(SEND).get(), &Button::clicked, this,
		&EchoSoundTestServicePage::sendData);
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
		(QByteArray(_inputs.at(MSG)->text().toStdString().c_str()),
		 QHostAddress(_inputs.at(IP_ADDRESS)->text()),
		 (quint16)(_inputs.at(PORT)->text().toInt()));
}
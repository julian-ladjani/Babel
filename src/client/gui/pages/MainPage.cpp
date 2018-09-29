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
	_logo(new Image("src/assets/img/sky.png", 600)),
	ABabelPage(_infos)
{
    	_container[MAIN] = std::make_unique<QGroupBox>();
    	_container[CONTACT] = std::make_unique<QGroupBox>();
    	_label[NAME] = std::make_unique<Label>("Lucas DEPRET");
    	_label[FAVORITE] = std::make_unique<Label>("Favorite");
    	_list[FAVORITE] =  std::make_unique<ListWidget>(QAbstractItemView::DropOnly);
	_label[SERVER] = std::make_unique<Label>("Server List");
    	_list[SERVER] =  std::make_unique<ListWidget>(QAbstractItemView::DragOnly);
	initSocket();
	connections();
}

void babel::client::MainPage::initSocket()
{
	auto addr = _infos.getClientInfo().getConnectionInfo().getIp();
	QHostAddress address(QString::fromStdString(addr));
	_udpSocket.bind(address);
	qDebug() << _udpSocket.localAddress().toString() << ":"
		 << _udpSocket.localPort();
	_layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    	QVBoxLayout *vbox = new QVBoxLayout;
    	QVBoxLayout *vbox2 = new QVBoxLayout;
    	vbox2->addWidget(_logo.get());
	vbox2->addWidget(_sender);
    	_container[MAIN]->setLayout(vbox2);
    	vbox->addWidget(_label[NAME].get());
    	vbox->addWidget(_label[FAVORITE].get());
    	vbox->addWidget(_list[FAVORITE].get());
    	vbox->addWidget(_label[SERVER].get());
    	_list[SERVER]->AddPersonne();
    	vbox->addWidget(_list[SERVER].get());
    	_container[CONTACT]->setLayout(vbox);
	_layout->addWidget(_container[CONTACT].get(), 0, 0, 1, 1);
	_layout->addWidget(_container[MAIN].get(), 0, 1, 1, 2);
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
		(QByteArray("coucou"), QHostAddress::LocalHost, 7755);
}
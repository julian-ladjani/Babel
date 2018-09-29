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
	_label{std::make_unique<Label>("Favorite"),
	       std::make_unique<Label>("Server List"),
	       std::make_unique<Label>("Lucas DEPRET")},
	_list{std::make_unique<ListWidget>(QAbstractItemView::DropOnly),
	      std::make_unique<ListWidget>(QAbstractItemView::DragOnly)},
	_container{std::make_unique<QGroupBox>(),
	        std::make_unique<QGroupBox>()},
	ABabelPage(_infos)
{
    	_infos.addContact(common::User("Lucas DE PRES", 0, true));
    	_infos.addContact(common::User("Gregory E.p.l.e", 1, false));
 	_infos.addContact(common::User("Julian Italien", 2, false));
	_infos.addContact(common::User("Yanick Sucre", 3, false));
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
    	QVBoxLayout *vbox = new QVBoxLayout;
    	QVBoxLayout *vbox2 = new QVBoxLayout;
    	QSplitter *splitter = new QSplitter();
    	_layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    	splitter->setOrientation(Qt::Horizontal);
    	vbox2->addWidget(_logo.get());
	vbox2->addWidget(_sender);
    	_container[MAIN]->setLayout(vbox2);
    	vbox->addWidget(_label[NAME].get());
    	vbox->addWidget(_label[FAVORITE].get());
    	vbox->addWidget(_list[FAVORITE].get());
    	vbox->addWidget(_label[SERVER].get());
    	_list[SERVER]->AddPersonne(_infos.getContacts());
    	vbox->addWidget(_list[SERVER].get());
    	_container[CONTACT]->setLayout(vbox);
    	splitter->addWidget(_container[CONTACT].get());
	splitter->addWidget(_container[MAIN].get());
	_layout->addWidget(splitter, 0,0);
	_layout->setRowStretch(0,1);
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
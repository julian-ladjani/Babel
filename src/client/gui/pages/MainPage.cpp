//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// MainPage.cpp
//

#include "MainPage.hpp"

babel::client::MainPage::MainPage(babel::client::ClientInfo &_infos) :
	ABabelPage(_infos),
	_udpSocket(this),
	_sender(new Button("SEND", STYLEDEFBUTTON, Size(500, 30))),
	_logo(new Image("src/assets/img/minilogo.png", 600)),
	_label({std::make_unique<Label>("Favorite"),
	       std::make_unique<Label>("Server List"),
	       std::make_unique<Label>("Lucas DEPRET")}),
	_container({std::make_unique<GroupBox>(),
		   std::make_unique<GroupBox>(),
		   std::make_unique<GroupBox>(),
		   std::make_unique<GroupBox>()}),
	_list({std::make_unique<ListWidget>(QAbstractItemView::DropOnly),
	      std::make_unique<ListWidget>(QAbstractItemView::DragOnly)}),
	_splitter({std::make_unique<QSplitter>(),
		  std::make_unique<QSplitter>()}),
	_vLayout({std::make_unique<QVBoxLayout>(),
		  std::make_unique<QVBoxLayout>()})
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
    	_layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    	_splitter[CENTER]->setOrientation(Qt::Horizontal);
    	_container[MAIN]->addWidget(_logo.get());
    	//_container[MAIN]->addWidget(_sender);
    	_splitter[LIST]->setOrientation(Qt::Vertical);
    	_container[CONTACT]->addWidget(_label[NAME].get());
    	_container[GBFAVORITE]->addWidget(_label[FAVORITE].get());
    	_container[GBFAVORITE]->addWidget(_list[FAVORITE].get());
	_splitter[LIST]->addWidget(_container[GBFAVORITE].get());
    	_container[GBSERVER]->addWidget(_label[SERVER].get());
    	_container[GBSERVER]->addWidget(_list[SERVER].get());
    	_list[SERVER]->AddPersonne(_infos.getContacts());
    	_splitter[LIST]->addWidget(_container[GBSERVER].get());
    	_container[CONTACT]->addWidget(_splitter[LIST].get());
    	_splitter[CENTER]->addWidget(_container[CONTACT].get());
	_splitter[CENTER]->addWidget(_container[MAIN].get());
	_layout->addWidget(_splitter[CENTER].get(), 0,0);
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
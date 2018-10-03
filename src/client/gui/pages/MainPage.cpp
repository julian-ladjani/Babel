//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// MainPage.cpp
//

#include <src/client/sound/AudioManager.hpp>
#include <src/client/sound/AudioEncoder.hpp>
#include "MainPage.hpp"

babel::client::MainPage::MainPage(babel::client::ClientInfo &_infos) :
	ABabelPage(_infos),
	_udpSocket(this),
	_test(false),
	_buttons({std::make_unique<Button>("src/assets/img/connect.png",
	StyleManager::ORANGEBUTTON, Size(55, 55)),
	std::make_unique<Button>("src/assets/img/mic.png",
	StyleManager::ORANGEBUTTON, Size(55, 55))}),
	_label({std::make_unique<Label>("Black List"),
	       std::make_unique<Label>("Server List"),
	       std::make_unique<Label>("")}),
	_list({std::make_unique<ListWidget>(QAbstractItemView::DropOnly),
	      std::make_unique<ListWidget>(QAbstractItemView::DragOnly)}),
	_container({std::make_unique<GroupBox>(),
		   std::make_unique<GroupBox>(),
		   std::make_unique<GroupBox>(),
		   std::make_unique<GroupBox>(),
		   std::make_unique<GroupBox>(new QHBoxLayout)}),
	_splitter({std::make_unique<QSplitter>(),
		  std::make_unique<QSplitter>()}),
	_logo(new Image("src/assets/img/minilogo.png", 600))
{
    	_infos.addContact(common::User("Lucas DE PRES", 0, true));
    	_infos.addContact(common::User("Gregory E.p.l.e", 1, false));
 	_infos.addContact(common::User("Julian Italien", 2, false));
	_infos.addContact(common::User("Yanick Sucre", 3, false));
	initSocket();
	initSideBar();
	initMain();
	connections();
}

void babel::client::MainPage::initSocket()
{
	auto addr = _infos.getClientInfo().getConnectionInfo().getIp();
	QHostAddress address(QString::fromStdString(addr));
	_udpSocket.bind(address);
	qDebug() << _udpSocket.localAddress().toString() << ":"
		 << _udpSocket.localPort();
}

void babel::client::MainPage::initSideBar() {
    	_layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    	_splitter[SCENTER]->setOrientation(Qt::Horizontal);
    	_splitter[SLIST]->setOrientation(Qt::Vertical);
    	_container[GBNAME]->addWidget(_buttons[BEXIT].get());
    	_container[GBNAME]->addWidget(_label[LNAME].get());
    	_container[GBNAME]->addWidget(_buttons[BTESTMIC].get());
    	_container[GBSIDEBAR]->addWidget(_container[GBNAME].get());
    	_container[GBCONTACT]->addWidget(_label[LFAVORITE].get());
    	_container[GBCONTACT]->addWidget(_list[LWFAVORITE].get());
	_splitter[SLIST]->addWidget(_container[GBCONTACT].get());
    	_container[GBSERVER]->addWidget(_label[LSERVER].get());
    	_container[GBSERVER]->addWidget(_list[LWSERVER].get());
    	_list[LWSERVER]->AddPersonne(_infos.getContacts());
    	_splitter[SLIST]->addWidget(_container[GBSERVER].get());
    	_container[GBSIDEBAR]->addWidget(_splitter[SLIST].get());
    	_splitter[SCENTER]->addWidget(_container[GBSIDEBAR].get());
}

void babel::client::MainPage::initMain() {
    	_container[GBMAIN]->addWidget(_logo.get());
	_splitter[SCENTER]->addWidget(_container[GBMAIN].get());
	_layout->addWidget(_splitter[SCENTER].get(), 0,0);
	_layout->setRowStretch(0,1);
	setLayout(_layout);
}

void babel::client::MainPage::connections()
{
	connect(&_udpSocket, &QUdpSocket::readyRead, this, &MainPage::readData);
	connect(_buttons[BEXIT].get(), &Button::clicked, this, &MainPage::changeToTestPage);
    	connect(_buttons[BTESTMIC].get(), &Button::clicked, this, &MainPage::testMic);

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

void babel::client::MainPage::setLogin() {
	_label[LNAME]->setText(QString::fromStdString
	(_infos.getClientInfo().getLogin()));
}

void babel::client::MainPage::changeToTestPage() {
    printf("lol\n");
    emit changePage("connection");
}

void babel::client::MainPage::testMic() {
    _test = !_test;
    if (_test) {
	thread1.start();
    }
    else{
        thread1.out();
        thread1.wait();
        thread1.quit();
    }
}

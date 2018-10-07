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
	_test(false),
	_buttons({std::make_unique<Button>("src/assets/img/connect.png",
	StyleManager::ORANGEBUTTON, Size(55, 55)),
	std::make_unique<Button>("src/assets/img/mic.png",
	StyleManager::ORANGEBUTTON, Size(55, 55))}),
	_labels({std::make_unique<Label>("Black List"),
	       std::make_unique<Label>("Server List"),
	       std::make_unique<Label>("")}),
	_lists({std::make_unique<ListWidget>(QAbstractItemView::DropOnly),
	      std::make_unique<ListWidget>(QAbstractItemView::DragOnly)}),
	_containers({new GroupBox(), new GroupBox(), new GroupBox(),
		     new GroupBox(), new GroupBox(new QHBoxLayout)}),
	_splitters({new QSplitter(), new QSplitter()}),
	_logo(new Image("src/assets/img/minilogo.png", 600)),
	_threadMic(std::make_unique<TMicro>(this)), _callSection(_infos)
{
    	_infos.addContact(common::User("Lucas Deloin", 0, true));
    	_infos.addContact(common::User("Gregory E.p.l.e", 1, false));
 	_infos.addContact(common::User("Julian Ladjani", 2, false));
	_infos.addContact(common::User("Yanick Sucre", 3, false));
	initSocket();
	initSideBar();
	initMain();
	connections();
}

babel::client::MainPage::~MainPage()
{
    if (_threadMic->is_loop()) {
	emit changeMic();
	_threadMic->wait();
	_threadMic->quit();
    }
}

void babel::client::MainPage::initSocket() {
    	auto addr = _infos.getClientInfo().getConnectionInfo().getIp();
	QHostAddress address(QString::fromStdString(addr));
	_udpSocket.bind(address);
	//qDebug() << _udpSocket.localAddress().toString() << ":"
	//	 << _udpSocket.localPort();
}


void babel::client::MainPage::initSideBar() {
    	_layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    	_splitters.at(SCENTER)->setOrientation(Qt::Horizontal);
    	_splitters.at(SLIST)->setOrientation(Qt::Vertical);
    	_containers.at(GBNAME)->addWidget(_buttons.at(BEXIT).get());
    	_containers.at(GBNAME)->addWidget(_labels.at(LNAME).get());
    	_containers.at(GBNAME)->addWidget(_buttons.at(BTESTMIC).get());
    	_containers.at(GBSIDEBAR)->addWidget(_containers.at(GBNAME));
    	_containers.at(GBCONTACT)->addWidget(_labels.at(LFAVORITE).get());
    	_containers.at(GBCONTACT)->addWidget(_lists.at(LWFAVORITE).get());
	_splitters.at(SLIST)->addWidget(_containers.at(GBCONTACT));
    	_containers.at(GBSERVER)->addWidget(_labels.at(LSERVER).get());
    	_containers.at(GBSERVER)->addWidget(_lists.at(LWSERVER).get());
    	_lists.at(LWSERVER)->AddPersonne(_infos.getContacts());
    	_splitters.at(SLIST)->addWidget(_containers.at(GBSERVER));
    	_containers.at(GBSIDEBAR)->addWidget(_splitters.at(SLIST));
    	_splitters.at(SCENTER)->addWidget(_containers.at(GBSIDEBAR));
}

void babel::client::MainPage::initMain() {
    	_containers.at(GBMAIN)->addWidget(&_callSection);
	_splitters.at(SCENTER)->addWidget(_containers.at(GBMAIN));
	_layout->addWidget(_splitters.at(SCENTER), 0, 0);
	_layout->setRowStretch(0, 1);
	setLayout(_layout);
}

void babel::client::MainPage::connections()
{
	connect(&_udpSocket, &QUdpSocket::readyRead, this, &MainPage::readData);
	connect(_buttons.at(BEXIT).get(),
		&Button::clicked, this, &MainPage::changeToConnectionPage);
    	connect(_buttons.at(BTESTMIC).get(),
		&Button::clicked, this, &MainPage::testMic);
    	connect(_lists.at(LWFAVORITE).get(), &QListWidget::itemActivated,
		this, &MainPage::updateActiveContact);
	connect(_lists.at(LWSERVER).get(), &QListWidget::itemActivated,
		this, &babel::client::MainPage::updateActiveContact);
	//connect(&_infos.getSocket(), &QTcpSocket::readyRead, &MainPage::readTcpData);
}

void babel::client::MainPage::readData()
{
	while (_udpSocket.hasPendingDatagrams()) {
		QNetworkDatagram datagram = _udpSocket.receiveDatagram();
	}
}

void babel::client::MainPage::updateActiveContact(QListWidgetItem *contactItem)
{
	int id = contactItem->data(Qt::UserRole).toInt();
	auto &contacts = _infos.getContacts();
	auto contact = *std::find(contacts.begin(), contacts.end(), id);
	_infos.setActiveUser(contact);
}

void babel::client::MainPage::sendData()
{
	_udpSocket.writeDatagram
		(QByteArray("coucou"), QHostAddress::LocalHost, 7755);
}

void babel::client::MainPage::setLogin()
{
    if (_infos.getClientInfo().getLogin().length() > 32)
	_labels[LNAME]->setText(QString::fromStdString
	(_infos.getClientInfo().getLogin()).left(29)+"...");
    else
	_labels[LNAME]->setText(QString::fromStdString
	(_infos.getClientInfo().getLogin()));
}

void babel::client::MainPage::changeToConnectionPage()
{
    if (_threadMic->is_loop()) {
	emit changeMic();
	_threadMic->wait();
    }
    emit disconnect();
}

void babel::client::MainPage::testMic()
{
   emit changeMic();
}

babel::client::CallPage &babel::client::MainPage::getCallSection()
{
	return _callSection;
}

void babel::client::MainPage::readTcpData() {
    common::DataPacket data = _infos.getSocket().receive();
    data.getArgs();
}

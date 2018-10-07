/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Window.cpp
*/

#include <QtWidgets/QMessageBox>
#include "ConnectionPage.hpp"

babel::client::ConnectionPage::ConnectionPage(babel::client::ClientInfo &_infos) :
	ABabelPage(_infos),
	_buttons{std::make_unique<Button>(
	"Logout", StyleManager::DEFAULTBUTTON, Size(500,30)),
	std::make_unique<Button>(
	"Options", StyleManager::HYPERTEXTBUTTON, Size(500,30)),
	std::make_unique<Button>(
	"Bouton de test tu sais pas se qui va se passer OMG",
	StyleManager::DEFAULTBUTTON, Size(500,30))},
	_inputs{std::make_unique<Input>(500, "Username"),
	std::make_unique<Input>(500, "Passworld"),
	std::make_unique<Input>(235, "IP Adress"),
	std::make_unique<Input>(235, "Port")},
	_logo(std::make_unique<Image>("src/assets/img/logo.png", 350)),
	_threadConversation(new TConversation(this)),
	_udpSocket(this),
	_audio(),
	_encode(_audio.getSampleRate(), _audio.getChannel())
{	_inputs.at(IP_ADDRESS)->setText("10.18.207.38");
	_inputs.at(LOGIN)->setEchoMode(QLineEdit::Password);
	_inputs.at(LOGIN)->setInputMethodHints(
		Qt::ImhHiddenText | Qt::ImhNoPredictiveText |
		Qt::ImhNoAutoUppercase);
	arrangeWidgets();
	connections();
	initSocket();
}

void babel::client::ConnectionPage::connections()
{
	connect(_buttons.at(OPTIONS).get(), &Button::clicked,
		this, &ConnectionPage::serverPropertiesSwitcher);
	connect(_buttons.at(CONNECTION).get(), &Button::clicked,
		this, &ConnectionPage::handleButton);
	connect(_buttons.at(TEST).get(), &Button::clicked,
		this, &ConnectionPage::changeToTestPage);

}

void babel::client::ConnectionPage::initSocket()
{
    auto addr = _infos.getClientInfo().getConnectionInfo().getIp();
    auto port = _infos.getClientInfo().getConnectionInfo().getPort();
    QHostAddress address(QString::fromStdString(addr));
    _udpSocket.bind(address, port);
    qDebug() << _udpSocket.localAddress().toString() << ":"
	     << _udpSocket.localPort();
    connect(&_udpSocket, &QUdpSocket::readyRead, this, &ConnectionPage::readAudio);
}

void babel::client::ConnectionPage::changeToTestPage()
{
    _threadConversation->changeContact(_inputs.at(IP_ADDRESS)->text(),
				       _inputs.at(PORT)->text().toInt());
    emit applyConversation();
}

std::vector<uint16_t> convert(QByteArray array)
{
    std::vector<uint16_t> tmp;
    char *charArray = array.data();
    for (int i = 0; i < array.size(); i += 2) {
	tmp.push_back((uint16_t)(charArray[i] + (charArray[i + 1] << 8)));
    }
    return tmp;
}

void babel::client::ConnectionPage::readAudio()
{
    printf("5/5 reçu!!\n");
    _audio.startStream();
    _audio.startRecording();
    while (_udpSocket.hasPendingDatagrams()) {
	QNetworkDatagram datagram = _udpSocket.receiveDatagram();
	std::vector<uint16_t> bufferToCompress = convert(datagram.data());
	_audio.playRecord(_encode.decode(bufferToCompress));
    }
    _audio.stopRecording();
    _audio.stopStream();
}

void babel::client::ConnectionPage::serverPropertiesSwitcher()
{
	_inputs.at(IP_ADDRESS)->setVisible
		(!_inputs.at(IP_ADDRESS)->isVisible());
	_inputs.at(PORT)->setVisible
		(!_inputs.at(PORT)->isVisible());
}

void babel::client::ConnectionPage::arrangeWidgets()
{
	_logo->setAlignment(Qt::AlignHCenter);
	_logo->setStyleSheet("padding-bottom: 80px;");
	_layout->addWidget(_logo.get(), 0, 0, 3, 2);
	_layout->addWidget(_inputs.at(LOGIN).get(), 2, 0, 1, 2);
	_layout->addWidget(_inputs.at(PASSWORD).get(), 3, 0, 1, 2);
	_layout->addWidget(_inputs.at(IP_ADDRESS).get(), 4, 0, 1, 1);
	_layout->addWidget(_inputs.at(PORT).get(), 4, 1, 1, 1);
	_layout->addWidget(_buttons.at(0).get(), 5, 0, 1, 2, Qt::AlignHCenter);
	_layout->addWidget(_buttons.at(1).get(), 6, 0, 1, 2, Qt::AlignHCenter);
	_layout->addWidget(_buttons.at(2).get(), 7, 0, 1, 2, Qt::AlignHCenter);
	_inputs.at(IP_ADDRESS)->setVisible(false);
	_inputs.at(PORT)->setVisible(false);
}

void babel::client::ConnectionPage::handleButton()
{
    	if (_inputs.at(LOGIN)->text() != "") {
    		_infos.getClientInfo().setLogin
			(_inputs.at(LOGIN)->text().toUtf8().constData());
		_infos.getClientInfo().setPassword
			(_inputs.at(PASSWORD)->text().toUtf8().constData());
	    emit changePage("main");
	}
	else {
	    QMessageBox msgBox;
	    msgBox.setText("Login or Passworld invalid");
	    msgBox.exec();
	}
}
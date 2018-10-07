/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Window.cpp
*/


#include "ConnectionPage.hpp"

babel::client::ConnectionPage::ConnectionPage(babel::client::ClientInfo &_infos) :
	ABabelPage(_infos),
	_buttons{std::make_unique<Button>(
	"Logout", StyleManager::DEFAULTBUTTON, Size(500, 30)),
	std::make_unique<Button>(
	"Options", StyleManager::HYPERTEXTBUTTON, Size(500, 30))},
	_inputs{std::make_unique<Input>(500, "Username"),
	std::make_unique<Input>(500, "Password"),
	std::make_unique<Input>(235, "IP Address"),
	std::make_unique<Input>(235, "Port")},
	_logo(std::make_unique<Image>("src/assets/img/logo.png", 350)),
	_threadConversation(new TConversation(this)),
	_udpSocket(this),
	_audio(),
	_encode(_audio.getSampleRate(), _audio.getChannel()),
	_timeStamp(0)
{
	initSocket();
	qDebug() << _udpSocket.localAddress().toString();
	_inputs.at(IP_ADDRESS)->setText(_udpSocket.localAddress().toString());
	_inputs.at(PORT)->setText("53876");
	_inputs.at(LOGIN)->setEchoMode(QLineEdit::Password);
	_inputs.at(LOGIN)->setInputMethodHints(
		Qt::ImhHiddenText | Qt::ImhNoPredictiveText |
		Qt::ImhNoAutoUppercase);
	arrangeWidgets();
	connections();
	_audio.startStream();
	_audio.startRecording();
}

void babel::client::ConnectionPage::connections()
{
	connect(_buttons.at(OPTIONS).get(), &Button::clicked,
		this, &ConnectionPage::serverPropertiesSwitcher);
	connect(_buttons.at(CONNECTION).get(), &Button::clicked,
		this, &ConnectionPage::handleButton);
}

void babel::client::ConnectionPage::initSocket()
{
    auto addr = _infos.getClientInfo().getConnectionInfo().getIp();
    auto port = _infos.getClientInfo().getConnectionInfo().getPort();
    QHostAddress address(QString::fromStdString(addr));
    _udpSocket.bind(address, port);
    qDebug() << _udpSocket.localAddress().toString() << ":"
	     << _udpSocket.localPort();
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
	_layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	_layout->addWidget(_logo.get(), 0, 0, 3, 2);
	_layout->addWidget(_inputs.at(LOGIN).get(), 2, 0, 1, 2);
	_layout->addWidget(_inputs.at(PASSWORD).get(), 3, 0, 1, 2);
	_layout->addWidget(_inputs.at(IP_ADDRESS).get(), 4, 0, 1, 1, Qt::AlignHCenter);
	_layout->addWidget(_inputs.at(PORT).get(), 4, 1, 1, 1, Qt::AlignHCenter);
	_layout->addWidget(_buttons.at(0).get(), 5, 0, 1, 2, Qt::AlignHCenter);
	_layout->addWidget(_buttons.at(1).get(), 6, 0, 1, 2, Qt::AlignHCenter);
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
		_infos.setServerInfo(common::ConnectionInfo(
			(uint16_t) _inputs.at(PORT)->text().toUInt(),
			_inputs.at(IP_ADDRESS)->text().toStdString()));
	    emit changePage("main");
	}
	else {
	    QMessageBox msgBox;
	    msgBox.setText("Login or Passworld invalid");
	    msgBox.exec();
	}
}
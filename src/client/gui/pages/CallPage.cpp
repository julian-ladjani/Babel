/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Window.cpp
*/

#include "CallPage.hpp"

babel::client::CallPage::CallPage(babel::client::ClientInfo &_infos) :
	ABabelPage(_infos),
	_buttons({std::make_unique<QPushButton>
	        (QIcon("src/assets/img/send.png"), ""),
		  std::make_unique<Button>("src/assets/img/mic.png",
			StyleManager::DEFAULTBUTTON, Size(45, 45))}),
	_chatInput("Type your message"), _chatBox(),
	_connectIcon("src/assets/img/off.png", 50),
	_contactName(QString(_infos.getActiveUser().getLogin().c_str()))
{
	setMinimumWidth(500);
	_buttons.at(SEND_MSG)->setFlat(true);
	_buttons.at(SEND_MSG)->setFixedSize(50, 50);
	_buttons.at(SEND_MSG)->setStyleSheet("\
                QPushButton {background-color: transparent;}   \
                QPushButton:active{background-color: transparent; border: none;"
					     "}");
	_chatInput.setFixedHeight(50);
	_chatInput.setAlignment(Qt::AlignLeft);
	_chatInput.setTextMargins(10, 0, 10, 0);
	_connectIcon.setFixedSize(50, 50);
	_contactName.setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	_contactName.setStyleSheet("background-color: transparent;"
			    "color:white;");
	update();
	_buttons.at(CALL)->setFixedSize(40, 40);
	_buttons.at(SEND_MSG)->setFixedSize(50, 50);
	arrangeWidgets();
	connections();
}

void babel::client::CallPage::connections()
{
	connect(&_infos, &ClientInfo::userUpdated, this, &CallPage::update);
	connect(_buttons.at(SEND_MSG).get(), &QPushButton::clicked,
		this, &CallPage::sendMessage);
}

void babel::client::CallPage::update()
{
	auto contact = _infos.getActiveUser();
	_contactName.setText(QString::fromStdString(contact.getLogin()));
	_connectIcon.update(contact.isConnected() ? "src/assets/img/off.png" :
			"src/assets/img/on.png", 50);
	_chatBox.setText(QString::fromStdString
				 (_infos.getActiveUser().getMessages()));
}

void babel::client::CallPage::arrangeWidgets()
{
	_layout->addWidget(&_connectIcon, 0, 0, 1, 1);
	_layout->addWidget(&_contactName, 0, 1, 1, 1);
	_layout->addWidget(_buttons.at(CALL).get(), 0, 2, 1, 1);
	_layout->addWidget(&_chatBox, 1, 0, 1, 3);
	_layout->addWidget(&_chatInput, 2, 0, 1, 3);
	_layout->addWidget(_buttons.at(SEND_MSG).get(), 2, 2, 1, 1);
	_layout->setSizeConstraint(QLayout::SetMaximumSize);
	_layout->setColumnStretch(2, 1);
	_layout->setRowStretch(2, 1);
}

void babel::client::CallPage::sendMessage()
{
	auto msg = _chatInput.text().toStdString();
	if (msg.empty())
		return;
	auto userName = std::string("<")
			+ std::string(_infos.getClientInfo().getLogin())
			+ std::string("> ");
	_chatBox.append(QString::fromStdString(userName + msg));
	auto tmpMsg = _chatBox.toPlainText().toStdString();
	_infos.getActiveUser().setMessages(tmpMsg);
	_chatInput.clear();
	emit sendMessageSignal(msg);
}

/*void babel::client::CallPage::receiveMessage()
{
}*/
/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Window.cpp
*/

#include "ConnectionPage.hpp"

babel::client::ConnectionPage::ConnectionPage(babel::client::ClientInfo &_infos)
	: _layout(new QGridLayout()), ABabelPage(_infos)
{
	QFontDatabase::addApplicationFont("src/assets/font/DejaVuSans.ttf");
	_layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	setLayout(_layout);
	submit();
}

void babel::client::ConnectionPage::home(QVBoxLayout *layout)
{
	QHBoxLayout *layout2 = new QHBoxLayout;
	QGroupBox *grlayout = new QGroupBox;
	Button *button = new Button("src/assets/img/add.png",
					STYLEDEFBUTTON, Size(100, 100));
	Button *button2 = new Button("src/assets/img/hangup.png",
					STYLEGREENBUTTON, Size(100, 100));
	layout2->addWidget(button2);
	layout2->addWidget(button);
	grlayout->setLayout(layout2);
	layout->addWidget(grlayout);
}

std::function<void()> babel::client::ConnectionPage::serverPropertiesSwitcher()
{
    return([this](){
	_input[0]->setVisible(!_input[0]->isVisible());
	_input[1]->setVisible(!_input[1]->isVisible());
    });
}
void babel::client::ConnectionPage::submit()
{
	Input *User = new Input(500, "Username");
	Input *Pass = new Input(500, "Password");
    	_input.push_back(new Input(235, "IP Adress"));
    	_input.push_back(new Input(235, "Port"));
	Button *button = new Button("Connection", STYLEDEFBUTTON, Size(500,30));
	Button *button2 = new Button("Server options", STYLEDEFA, Size(500,30));
	button2->setFunction(serverPropertiesSwitcher());
	Image *logo = new Image("src/assets/img/logo.png", 350);
	logo->setAlignment(Qt::AlignHCenter);
	logo->setStyleSheet("padding-bottom: 80px;");
	_layout->addWidget(logo, 0, 0, 3, 2);
	_layout->addWidget(User, 2, 0, 1, 2);
	_layout->addWidget(Pass, 3, 0, 1, 2);
	_layout->addWidget(_input[0], 4, 0, 1, 1);
	_layout->addWidget(_input[1], 4, 1, 1, 1);
	_layout->addWidget(button, 5, 0, 1, 2, Qt::AlignHCenter);
	_layout->addWidget(button2, 6, 0, 1, 2, Qt::AlignHCenter);
}

/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Window.cpp
*/

#include <memory>
#include "ConnectionPage.hpp"

babel::client::ConnectionPage::ConnectionPage(babel::client::ClientInfo &_infos)
	: _layout(new QGridLayout()), ABabelPage(_infos)
{
	_buttons[CONNECTION] = std::make_unique<Button>(
		"Connection", STYLEDEFBUTTON, Size(500,30));
	_buttons[OPTIONS] = std::make_unique<Button>(
		"Options", STYLEDEFA, Size(500,30));
	_inputs[LOGIN] = std::make_unique<Input>(500, "Username");
	_inputs[PASSWORD] = std::make_unique<Input>(500, "Password");
	_inputs[IP_ADDRESS] = std::make_unique<Input>(235, "IP Adress");
	_inputs[PORT] = std::make_unique<Input>(235, "Port");
	_logo = std::make_unique<Image>("src/assets/img/logo.png", 350);
	QFontDatabase::addApplicationFont("src/assets/font/DejaVuSans.ttf");
	_layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	setLayout(_layout);
	arrangeWidgets();
}

std::function<void()> babel::client::ConnectionPage::serverPropertiesSwitcher()
{
    return ([this](){
	_inputs.at(IP_ADDRESS)->setVisible(
		!_inputs.at(IP_ADDRESS)->isVisible());
	_inputs.at(PORT)->setVisible(
		!_inputs.at(PORT)->isVisible());
    });
}
void babel::client::ConnectionPage::arrangeWidgets()
{
	_buttons.at(OPTIONS)->setFunction(serverPropertiesSwitcher());
	_logo->setAlignment(Qt::AlignHCenter);
	_logo->setStyleSheet("padding-bottom: 80px;");
	_layout->addWidget(_logo.get(), 0, 0, 3, 2);
	_layout->addWidget(_inputs.at(LOGIN).get(), 2, 0, 1, 2);
	_layout->addWidget(_inputs.at(PASSWORD).get(), 3, 0, 1, 2);
	_layout->addWidget(_inputs.at(IP_ADDRESS).get(), 4, 0, 1, 1);
	_layout->addWidget(_inputs.at(PORT).get(), 4, 1, 1, 1);
	_layout->addWidget(_buttons.at(0).get(), 5, 0, 1, 2, Qt::AlignHCenter);
	_layout->addWidget(_buttons.at(1).get(), 6, 0, 1, 2, Qt::AlignHCenter);
	_inputs.at(IP_ADDRESS)->setVisible(false);
	_inputs.at(PORT)->setVisible(false);
}

/*void babel::client::ConnectionPage::home(QVBoxLayout *layout)
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
}*/
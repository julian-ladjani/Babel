/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Window.cpp
*/

#include "ConnectionPage.hpp"

babel::client::ConnectionPage::ConnectionPage() : _layout(new QVBoxLayout())
{
	QFontDatabase::addApplicationFont("src/assets/font/DejaVuSans.ttf");
	Image  *image  = new Image("src/assets/img/logo.png", 400);
	_layout->addWidget(image);
	_layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	setLayout(_layout);
	delete image;
	submit(_layout);
}

void babel::client::ConnectionPage::home(QVBoxLayout *layout)
{
	QHBoxLayout *layout2 = new QHBoxLayout;
	QGroupBox *grlayout = new QGroupBox;
	Button *button = new Button("src/assets/img/add.png", STYLEDEFBUTTON, Size(100,100));
	Button *button2 = new Button("src/assets/img/hangup.png", STYLEGREENBUTTON, Size(100,100));
	layout2->addWidget(button2);
	layout2->addWidget(button);
	grlayout->setLayout(layout2);
	layout->addWidget(grlayout);
}

std::function<void()> babel::client::ConnectionPage::lol()
{
    return([this](){
	_input[0]->setVisible(!_input[0]->isVisible());
	_input[1]->setVisible(!_input[1]->isVisible());
    });
}
void babel::client::ConnectionPage::submit(QVBoxLayout *layout)
{
	Input *User = new Input(500, "Username");
	Input *Pass = new Input(500, "Password");
	std::cout << "lol\n";
    	_input.push_back(new Input(200, "Adress IP"));
    	_input.push_back(new Input(200, "Port"));
	std::cout << "lol\n";
	Button *button = new Button("Enter", STYLEDEFBUTTON, Size(200,50));
	Button *button2 = new Button("Option", STYLEDEFA, Size(125,40));
	button2->setFunction(lol());
	Image *logo = new Image("src/assets/img/logo.png", 350);
	logo->setAlignment(Qt::AlignHCenter);
	logo->setStyleSheet("padding-bottom: 80px;");
	layout->addWidget(logo);
	layout->addWidget(User);
	layout->addWidget(Pass);
	layout->addWidget(_input[0], 0, Qt::AlignHCenter);
	layout->addWidget(_input[1], 0, Qt::AlignHCenter);
	layout->addWidget(button, 0, Qt::AlignHCenter);
	layout->addWidget(button2, 0, Qt::AlignHCenter);
}
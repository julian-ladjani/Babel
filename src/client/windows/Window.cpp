/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Window.cpp
*/

#include "Window.hpp"

babel::client::MainWindow::MainWindow() : _layout(new QVBoxLayout())
{
	resize(1280, 720);
	QFontDatabase::addApplicationFont("src/assets/font/DejaVuSans.ttf");
	setWindowTitle(QApplication::translate(
		"Epyks", "Epyks, Grand et impuissant !"));
	setStyleSheet("background-color:#3d3d3d");
	Image  *image  = new Image("src/assets/img/logo.png", 400);
	_layout->addWidget(image);
	_layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	setLayout(_layout);
	delete image;
	Submit(_layout);
}

void babel::client::MainWindow::Home(QVBoxLayout *layout)
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

std::function<void()> babel::client::MainWindow::lol()
{
    return([this](){
	_input[0]->setVisible(!_input[0]->isVisible());
	_input[1]->setVisible(!_input[1]->isVisible());
    });
}
void babel::client::MainWindow::Submit(QVBoxLayout *layout)
{
	QLabel  *label  = new QLabel;
	Input *User = new Input(500, "Username");
	Input *Pass = new Input(500, "Password");
	std::cout << "lol\n";
    	_input.push_back(new Input(200, "Adress IP"));
    	_input.push_back(new Input(200, "Port"));
	std::cout << "lol\n";
	Button *button = new Button("Enter", STYLEDEFBUTTON, Size(200,50));
	Button *button2 = new Button("Option", STYLEDEFA, Size(125,40));
	button2->setFunction(lol());
	QPixmap pixmap_img("src/assets/img/logo.png");
	if (pixmap_img.height() != 0)
		pixmap_img = pixmap_img.scaled(
			350, pixmap_img.height() * 350 / pixmap_img.width(),
			Qt::IgnoreAspectRatio);
	label->setPixmap(pixmap_img);
	label->setAlignment(Qt::AlignHCenter);
	label->setStyleSheet("padding-bottom: 80px;");
	layout->addWidget(label);
	layout->addWidget(User);
	layout->addWidget(Pass);
	layout->addWidget(_input[0], 0, Qt::AlignHCenter);
	layout->addWidget(_input[1], 0, Qt::AlignHCenter);
	layout->addWidget(button, 0, Qt::AlignHCenter);
	layout->addWidget(button2, 0, Qt::AlignHCenter);
}
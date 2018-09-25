//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// Window.cpp
//
#include "Window.hpp"


babel::client::MainWindow::MainWindow()
{
	resize(1280, 720);
	setWindowTitle(QApplication::translate(
		"Epyks", "Epyks, Grand et impuissant !"));
	setStyleSheet("background-color:#3d3d3d");
	QLabel  *label  = new QLabel;
	QPixmap pixmap_img("src/assets/logo.png");
	pixmap_img = pixmap_img.scaled(
		400, pixmap_img.height() * 400 / pixmap_img.width(),
		Qt::IgnoreAspectRatio);
	label->setPixmap(pixmap_img);
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(label);
	layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	setLayout(layout);
	delete label;
	Submit(layout);
}

void babel::client::MainWindow::Home(QVBoxLayout *layout)
{
	QHBoxLayout *layout2 = new QHBoxLayout;
	QGroupBox *grlayout = new QGroupBox;
	Button *button = new Button("src/assets/add.png", STYLEDEFBUTTON, Size(100,100));
	Button *button2 = new Button("src/assets/hangup.png", STYLEGREENBUTTON, Size(100,100));
	layout2->addWidget(button2);
	layout2->addWidget(button);
	grlayout->setLayout(layout2);
	layout->addWidget(grlayout);
}

void babel::client::MainWindow::Submit(QVBoxLayout *layout)
{
	QLabel  *label  = new QLabel;
	Input *User = new Input(500, "Username");
	Input *Pass = new Input(500, "Password");
	Input *IP = new Input(200, "Adress IP");
	Input *Port = new Input(200, "Port");
	Button *button2 = new Button("More", STYLEDEFBUTTON, Size(125,40));
	Button *button = new Button("Enter", STYLEDEFBUTTON, Size(200,50));
	QPixmap pixmap_img("src/assets/logo.png");
	pixmap_img = pixmap_img.scaled(350, pixmap_img.height() * 350 / pixmap_img.width(), Qt::IgnoreAspectRatio);
	label->setPixmap(pixmap_img);
	label->setAlignment(Qt::AlignHCenter);
	label->setStyleSheet("padding-bottom: 80px;");
	layout->addWidget(label);
	layout->addWidget(User);
	layout->addWidget(Pass);
	layout->addWidget(IP, 0, Qt::AlignHCenter);
	layout->addWidget(Port, 0, Qt::AlignHCenter);
	layout->addWidget(button2, 0, Qt::AlignHCenter);
	layout->addWidget(button, 0, Qt::AlignHCenter);
}
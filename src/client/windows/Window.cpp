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

std::function<void()> babel::client::MainWindow::showOption()
{
    return[this](){
	_connection.getWidget("4IP")->setVisible(!_connection.getWidget("4IP")->isVisible());
	_connection.getWidget("5Port")->setVisible(!_connection.getWidget("5Port")->isVisible());
    };
}

std::function<void()> babel::client::MainWindow::connection()
{
    return [this]() {
	QMessageBox msgBox;
	msgBox.setIcon(QMessageBox::Warning);
	msgBox.setWindowTitle("Epyks");
	msgBox.setText("Username or Passworld Invalid");
	msgBox.exec();
	//_connection.setVisible(false);
    };
}

void babel::client::MainWindow::Submit(QVBoxLayout *layout)
{
    	_connection.addWidget(new Image("src/assets/img/logo.png", 350), "1Logo");
    	_connection.addWidget(new Input(500, "Username"), "2User");
    	_connection.addWidget(new Input(500, "Password"), "3Pass");
    	_connection.addWidget(new Input(200, "Address IP"), "4IP");
    	_connection.getWidget("4IP")->setVisible(false);
    	_connection.addWidget(new Input(200, "Port"), "5Port");
    	_connection.getWidget("5Port")->setVisible(false);
    	_connection.addWidget(new Button("Connetion", STYLEDEFBUTTON, Size(200,50)), "Connection");
    	_connection.addWidget(new Button("Option", STYLEDEFA, Size(125,40)), "Option");
	_connection.getButton("Option")->setFunction(showOption());
	_connection.getButton("Connection")->setFunction(connection());
    	setStyleSheet("padding-bottom: 80px;");
	_connection.addInLayout(layout, Qt::AlignHCenter);
}
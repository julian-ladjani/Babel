//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// Window.cpp
//
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "QApplication"
#include "Window.hpp"

babel::client::MainWindow::MainWindow()
{
	resize(1280, 720);
	show();
	setWindowTitle(QApplication::translate(
		"Epyks", "Epyks, Grand et impuissant !"));
	setStyleSheet("background-color:#2B2B2B;");
	QLabel  *label  = new QLabel;
	QPixmap pixmap_img("src/assets/logo.png");
	pixmap_img = pixmap_img.scaled(
		400, pixmap_img.height() * 400 / pixmap_img.width(),
		Qt::IgnoreAspectRatio);
	label->setPixmap(pixmap_img);
	label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(label);
	Button *button = new Button("src/assets/call.png");
	button->setEnabled(true);
	layout->addWidget(button);
	setLayout(layout);
	show();
}
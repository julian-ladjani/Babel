/*
** EPITECH PROJECT, 2018
** CPP_Babel_2018
** File description:
** Button.cpp
*/

#include "Button.hpp"

Button::Button(const QString &text)
{
	std::ifstream infile;
	std::string utf8_text = text.toUtf8().constData();
	infile.open(utf8_text, std::ios::in);
	std::cout << utf8_text << std::endl;
	if (infile) {
		setIcon(QIcon(text));
	}
	else
		setText(text);
	setIconSize(QSize(50, 50));
	setStyleSheet(STYLEBUTTON);
	QRect rect(1, 1, 70, 70);
	QRegion region(rect, QRegion::Ellipse);
	setMask(region);
}

Button::~Button()
{
}

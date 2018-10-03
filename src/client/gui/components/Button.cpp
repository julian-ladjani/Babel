/*
** EPITECH PROJECT, 2018
** CPP_Babel_2018
** File description:
** Button.cpp
*/

#include "Button.hpp"

babel::client::Button::Button(const QString &text, StyleManager::Sheet style, Size size)
{
	std::ifstream infile;
	std::string utf8_text = text.toUtf8().constData();
	infile.open(utf8_text, std::ios::in);
	if (infile)
		setIcon(QIcon(text));
	else
		setText(text);
	setIconSize(QSize(size.getY()/1.3, size.getY()/1.3));
	auto stylewidth = QStringLiteral("QPushButton {"
			"min-width:%1px;"
			"max-width:%1px;}").arg(size.getX());
	auto styleheight =QStringLiteral("QPushButton {"
			"min-height:%1px;"
			"max-height:%1px;}").arg(size.getY());
	setStyleSheet(_style.getSheet(style)+styleheight+stylewidth);
    	setEnabled(true);
}

babel::client::Button::~Button()
{
}
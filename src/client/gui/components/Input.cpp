/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Input.cpp
*/

#include "Input.hpp"

babel::client::Input::Input(int size, QString placeholders)
{
	setPlaceholderText(placeholders);
	setAlignment(Qt::AlignHCenter);
	auto tmp = QStringLiteral("QLineEdit {"
			"margin: 10px;"
			"border-radius: 15px;"
			"min-width:%1px;"
			"min-height:30px;}").arg(size);
	setStyleSheet("QLineEdit { background-color: white }" + tmp);
    	setFocus();
}

babel::client::Input::Input(QString placeholders)
{
	setPlaceholderText(placeholders);
	setAlignment(Qt::AlignHCenter);
	auto tmp = QStringLiteral("QLineEdit {"
				  "margin: 10px;"
				  "border-radius: 15px;"
				  "min-width:%1px;"
				  "min-height:30px;}");
	setStyleSheet("QLineEdit { background-color: white }" + tmp);
	setFocus();
}

babel::client::Input::~Input()
{
}

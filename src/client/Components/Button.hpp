/*
** EPITECH PROJECT, 2018
** CPP_Babel_2018
** File description:
** Button.hpp
*/

#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "QApplication"
#include <QRegion>
#include <QRect>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <fstream>

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

const QString STYLEBUTTON = "QPushButton { background-color: red;"
		"border: none;"
    		"font: bold 30px;"
		"max-width:71px;"
		"max-height:71px;"
		"min-width:71px;"
		"min-height:71px;}"
		"QPushButton:pressed {"
		"background-color: rgb(224, 0, 0);border-style: inset;}";

class Button : public QPushButton
{
	public:
		Button(const QString &text);
		~Button();

	protected:
	private:
};

#endif /* !BUTTON_HPP_ */

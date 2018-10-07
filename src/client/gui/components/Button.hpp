/*
** EPITECH PROJECT, 2018
** CPP_Babel_2018
** File description:
** Button.hpp
*/

#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QFontDatabase>
#include <QApplication>
#include <QRegion>
#include <QRect>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "Size.hpp"
#include "StyleManager.hpp"
#include <QHoverEvent>

#ifndef BUTTON_HPP_
#define BUTTON_HPP_


namespace babel {
    namespace client {

	class Button : public QPushButton
	{
	public:
	    Button(const QString &text, StyleManager::Sheet style, Size size);
	    ~Button();
	protected:
	private:
	    StyleManager _style;
	};
    }
}

#endif /* !BUTTON_HPP_ */

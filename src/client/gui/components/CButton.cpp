/*
** EPITECH PROJECT, 2018
** CPP_Babel_2018
** File description:
** CButton.cpp
*/

#include "CButton.hpp"

babel::client::CButton::CButton(const QString &text, const QString style, int size) :
	Button(text, style, size)
{
	QRect rect(0, 0, size, size);
	QRegion region(rect, QRegion::Ellipse);
	setMask(region);
}

babel::client::CButton::~CButton()
{
}

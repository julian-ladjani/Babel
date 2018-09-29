/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Label.cpp
*/

#include "Label.hpp"

babel::client::Label::Label(const QString text)
{
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setText(text);
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    setStyleSheet("background-color: #f04c00;font: bold 24px;");
}

babel::client::Label::~Label()
{
}

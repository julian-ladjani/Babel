/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** GroupeBox.cpp
*/

#include "GroupBox.hpp"


babel::client::GroupBox::GroupBox(QBoxLayout *layout) {
    _layout = layout;
    setLayout(layout);
}

babel::client::GroupBox::~GroupBox()
{
}

QWidget *babel::client::GroupBox::addWidget(QWidget *widget) {
    _layout->addWidget(widget);
    return widget;
}

/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** GroupeBox.cpp
*/

#include "GroupBox.hpp"


babel::client::GroupBox::GroupBox(QBoxLayout *layout) {
    _layout = layout;
    _layout->setAlignment(Qt::AlignVCenter);
    setLayout(layout);
}

QWidget *babel::client::GroupBox::addWidget(QWidget *widget) {
    _layout->addWidget(widget);
    _list.push_back(widget);
    return widget;
}

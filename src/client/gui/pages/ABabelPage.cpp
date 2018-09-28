/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ABabelPage.cpp
*/

#include "ABabelPage.hpp"

babel::client::ABabelPage::ABabelPage(babel::client::ClientInfo &_infos) :
	_infos(_infos), _layout(new QGridLayout())
{
	_layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	setLayout(_layout);
}

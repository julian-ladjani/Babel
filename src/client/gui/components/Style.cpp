/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Style.cpp
*/

#include "Style.hpp"

babel::client::Style::Style(QString type, QString mode)
{
    _styleSheet.push_back(QStringLiteral("%1").arg(type) +
    QStringLiteral("%1{").arg(mode));
}

babel::client::Style::~Style()
{
}

void babel::client::Style::setWidth(int size)
{
    _styleSheet.push_back(
            QStringLiteral("min-width:%1px;max-width:%1px;").arg(size));
}

void babel::client::Style::setHeight(int size)
{
    _styleSheet.push_back(
            QStringLiteral("min-height:%1px;max-height:%1px;").arg(size));
}

void babel::client::Style::setBackground(QString color)
{
    _styleSheet.push_back(QStringLiteral("background-color:%1;").arg(color));
}

void babel::client::Style::setColor(QString color)
{
    _styleSheet.push_back(QStringLiteral("color:%1;").arg(color));
}

void babel::client::Style::setFont(QString fond)
{
    _styleSheet.push_back(QStringLiteral("font:%1;").arg(fond));
}

void babel::client::Style::setBorder(QString border, int radius)
{
    _styleSheet.push_back(
            QStringLiteral("border:%1;").arg(border)+
            QStringLiteral("border-radius:%1;").arg(radius));
}

void babel::client::Style::setExtra(QString extra) {
    _styleSheet.push_back(QStringLiteral("%1;").arg(extra));

}

QString babel::client::Style::getStyleStreet() const
{
    QString style("");
    for (int i = 0; i < _styleSheet.size(); i++)
        style += _styleSheet[i];
    style += "}";
    return style;
}


/*
** EPITECH PROJECT, 2018
** CPP_Babel_2018
** File description:
** Image.cpp
*/

#include "Image.hpp"

babel::client::Image::Image(const QString text, int size)
{
    QPixmap pixmap_img(text);
    if (pixmap_img.height() == 0 || pixmap_img.width() == 0)
	    return ;
    pixmap_img = pixmap_img.scaled(
	    size, pixmap_img.height() * size / pixmap_img.width(),
	    Qt::IgnoreAspectRatio);
    setPixmap(pixmap_img);
}

babel::client::Image::~Image()
{
}

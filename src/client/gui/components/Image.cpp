/*
** EPITECH PROJECT, 2018
** CPP_Babel_2018
** File description:
** Image.cpp
*/

#include "Image.hpp"

babel::client::Image::Image(const QString text, int size)
{
	update(text, size);
}

void babel::client::Image::update(const QString text, int size)
{
	std::ifstream infile;
	std::string utf8_text = text.toUtf8().constData();
	infile.open(utf8_text, std::ios::in);
	if (!infile)
		throw babel::common::Exception(
			"QtImageError", "Error while loading the image");
	QPixmap pixmap_img(text);
	if (pixmap_img.height() == 0 || pixmap_img.width() == 0)
		throw babel::common::Exception(
			"QtImageError", "Error while loading the image");
	pixmap_img = pixmap_img.scaled(
		size, pixmap_img.height() * size / pixmap_img.width(),
		Qt::IgnoreAspectRatio);
	setAlignment(Qt::AlignHCenter);
	setPixmap(pixmap_img);
}

babel::client::Image::~Image()
{
}

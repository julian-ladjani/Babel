/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Size.cpp
*/

#include "Size.hpp"

Size::Size(int x, int y, int z) : X(x), Y(y), Z(z)
{
}

Size::~Size()
{
}

int Size::getX() const
{
	return X;
}
int Size::getY() const
{
	return Y;
}
int Size::getZ() const
{
	return Z;
}
void Size::setX(int x)
{
	X = x;
}
void Size::setY(int y)
{
	Y = y;
}
void Size::setZ(int z)
{
	Z = z;
}
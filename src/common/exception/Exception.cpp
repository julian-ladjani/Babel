/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Exception.cpp
*/

#include "Exception.hpp"

babel::common::Exception::Exception(const std::string &context,
	const std::string &message)
{
	_what = context + ": "  + message;
}

const char *babel::common::Exception::what() const noexcept
{
	return _what.c_str();
}

/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	TcpServerException class
*/

#include "TcpServerException.hpp"

babel::server::TcpServerException::TcpServerException(
	const std::string &message) : Exception("Tcp Server Error", message)
{
}

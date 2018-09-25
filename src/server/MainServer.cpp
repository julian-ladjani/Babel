/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** MainServer.cpp
*/

#include <src/server/Server.hpp>

int main(int argc, char *argv[])
{
	babel::server::Server server;
	server.start();
	return 0;
}
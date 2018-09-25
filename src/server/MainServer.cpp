//
// EPITECH PROJECT, 2018
// CPP_babel_2018 - MainServer.cpp
// File description:
// Created by Gregory EPLE
//

#include <src/server/Server.hpp>

int main(int argc, char *argv[])
{
	babel::server::Server server;
	server.start();
	return 0;
}
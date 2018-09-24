#include <src/server/Server.hpp>

int main(int argc, char *argv[])
{
	babel::server::Server server;
	server.start();
	return 0;
}
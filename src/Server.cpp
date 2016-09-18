#include "Server.h"

#include <iostream>

int Server::main(const std::vector<std::string>& args)
{
	std::cout << "start" << std::endl;
	waitForTerminationRequest();
	std::cout << "stop" << std::endl;
	return 0;
}

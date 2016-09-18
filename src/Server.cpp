#include "Server.h"

#include "handlers/Factory.h"

#include <iostream>
#include <Poco/Net/HTTPServer.h>

int Server::main(const std::vector<std::string>& args)
{
	Poco::Net::HTTPServerParams::Ptr parameters = new Poco::Net::HTTPServerParams();
	parameters->setTimeout(10000);
	parameters->setMaxQueued(100);
	parameters->setMaxThreads(4);

	const Poco::Net::ServerSocket socket(5849);

	Poco::Net::HTTPServer server(new handlers::Factory(), socket, parameters);

	server.start();
	waitForTerminationRequest();
	server.stopAll();

	return 0;
}

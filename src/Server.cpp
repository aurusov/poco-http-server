#include "Server.h"

#include "handlers/Factory.h"

#include <iostream>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/ServerSocketImpl.h>

namespace
{

class ServerSocketImpl: public Poco::Net::ServerSocketImpl
{
public:
	using Poco::Net::SocketImpl::init;
};

class Socket: public Poco::Net::Socket
{
public:
	Socket(const std::string & address)
		: Poco::Net::Socket(new ServerSocketImpl())
	{
		const Poco::Net::SocketAddress socket_address(address);
		ServerSocketImpl * socket = static_cast<ServerSocketImpl*>(impl());
		socket->init(socket_address.af());
		socket->setReuseAddress(true);
		socket->setReusePort(false);
		socket->bind(socket_address, false);
		socket->listen();
	}
};

} // anonymous namespace

int Server::main(const std::vector<std::string>& args)
{
	Poco::Net::HTTPServerParams::Ptr parameters = new Poco::Net::HTTPServerParams();
	parameters->setTimeout(10000);
	parameters->setMaxQueued(100);
	parameters->setMaxThreads(4);

	const Poco::Net::ServerSocket socket(Socket("localhost:5849"));

	Poco::Net::HTTPServer server(new handlers::Factory(), socket, parameters);

	server.start();
	waitForTerminationRequest();
	server.stopAll();

	return 0;
}

#include "Factory.h"

#include "Ping.h"

#include <Poco/Net/HTTPServerRequest.h>

namespace handlers
{

Poco::Net::HTTPRequestHandler* Factory::createRequestHandler(
	const Poco::Net::HTTPServerRequest& request)
{
	if (request.getURI() == "/ping")
		return new Ping();

	return nullptr;
}

} // namespace handlers

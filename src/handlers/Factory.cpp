#include "Factory.h"

#include "Ping.h"

#include <Poco/Net/HTTPServerRequest.h>

namespace handlers
{

Poco::Net::HTTPRequestHandler* Factory::createRequestHandler(
	const Poco::Net::HTTPServerRequest& request)
{
	if (request.getMethod() != Poco::Net::HTTPRequest::HTTP_GET)
		return nullptr;

	if (request.getURI() == "/ping")
		return new Ping();

	return nullptr;
}

} // namespace handlers

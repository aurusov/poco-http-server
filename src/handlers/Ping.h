#pragma once

#include <Poco/Net/HTTPRequestHandler.h>

namespace handlers
{

class Ping: public Poco::Net::HTTPRequestHandler
{
private:
	void handleRequest(
		Poco::Net::HTTPServerRequest& request,
		Poco::Net::HTTPServerResponse& response) override;
};

} // namespace handlers

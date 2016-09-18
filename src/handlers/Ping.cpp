#include "Ping.h"

#include <Poco/Net/HTTPServerResponse.h>

namespace handlers
{

void Ping::handleRequest(
	Poco::Net::HTTPServerRequest& request,
	Poco::Net::HTTPServerResponse& response)
{
	response.send().flush();
	response.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
}

} // namespace handlers

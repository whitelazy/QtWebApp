/**
  @file
  @author Stefan Frings
*/

#include "httprequesthandler.h"

using namespace stefanfrings;

HttpRequestHandler::HttpRequestHandler(QObject *parent)
    : QObject(parent)
{ }

HttpRequestHandler::~HttpRequestHandler()
{ }

void HttpRequestHandler::service(HttpRequest &request, HttpResponse &response)
{
    qCritical("HttpRequestHandler: you need to override the service() function");
    qDebug("HttpRequestHandler: request=%s %s %s", request.getMethod().data(), request.getPath().data(), request.getVersion().data());
    response.setStatus(501, "not implemented");
    response.write("501 not implemented", true);
}

bool HttpRequestHandler::authorize(HttpRequest &request, HttpResponse &response)
{
    return true;
}

void HttpRequestHandler::newHttpConnectionIncomming(HttpRequest *request)
{ }

void HttpRequestHandler::newHttpRequestIncomming(HttpRequest *request)
{ }

void HttpRequestHandler::httpRequestHeaderRecieved(HttpRequest *request)
{ }

void HttpRequestHandler::httpRequestAccessDenied(HttpRequest *request)
{ }

void HttpRequestHandler::httpRequestBodyReceived(HttpRequest *request)
{ }

void HttpRequestHandler::httpRequestAborted(HttpRequest *request)
{ }

void HttpRequestHandler::httpRequestTimeout(HttpRequest *request)
{ }

void HttpRequestHandler::httpRequestCompleted(HttpRequest *request)
{ }

void HttpRequestHandler::httpRequestFinished(HttpRequest *request)
{ }

void HttpRequestHandler::httpRequestExpired(HttpRequest *request)
{ }

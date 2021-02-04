/**
  @file
  @author Stefan Frings
*/

#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H

#include "httprequesthandler.h"

using namespace stefanfrings;

/**
  The request mapper dispatches incoming HTTP requests to controller classes
  depending on the requested path.
*/

class RequestMapper : public HttpRequestHandler
{
    Q_OBJECT
    Q_DISABLE_COPY(RequestMapper)
public:
    /**
      Constructor.
      @param parent Parent object
    */
    RequestMapper(QObject *parent = 0);

    /**
      Destructor.
    */
    ~RequestMapper();

    /**
      Dispatch incoming HTTP requests to different controllers depending on the URL.
      @param request The received HTTP request
      @param response Must be used to return the response
    */
    void service(HttpRequest &request, HttpResponse &response) override;

    // HttpRequestHandler interface
public:
    bool authorize(HttpRequest &request, HttpResponse &response) override;
    void newHttpConnectionIncomming(HttpRequest *request) override;
    void newHttpRequestIncomming(HttpRequest *request) override;
    void httpRequestHeaderRecieved(HttpRequest *request) override;
    void httpRequestAccessDenied(HttpRequest *request) override;
    void httpRequestBodyReceived(HttpRequest *request) override;
    void httpRequestAborted(HttpRequest *request) override;
    void httpRequestTimeout(HttpRequest *request) override;
    void httpRequestCompleted(HttpRequest *request) override;
    void httpRequestFinished(HttpRequest *request) override;
    void httpRequestExpired(HttpRequest *request) override;
};

#endif // REQUESTMAPPER_H

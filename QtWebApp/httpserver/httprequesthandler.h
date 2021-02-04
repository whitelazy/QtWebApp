/**
  @file
  @author Stefan Frings
*/

#ifndef HTTPREQUESTHANDLER_H
#define HTTPREQUESTHANDLER_H

#include "httpglobal.h"
#include "httprequest.h"
#include "httpresponse.h"

namespace stefanfrings {

/**
   The request handler generates a response for each HTTP request. Web Applications
   usually have one central request handler that maps incoming requests to several
   controllers (servlets) based on the requested path.
   <p>
   You need to override the service() method or you will always get an HTTP error 501.
   <p>
   @warning Be aware that the main request handler instance must be created on the heap and
   that it is used by multiple threads simultaneously.
   @see StaticFileController which delivers static local files.
*/

class DECLSPEC HttpRequestHandler : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(HttpRequestHandler)
public:
    /**
     * Constructor.
     * @param parent Parent object.
     */
    HttpRequestHandler(QObject *parent = nullptr);

    /** Destructor */
    virtual ~HttpRequestHandler();

    /**
      Generate a response for an incoming HTTP request.
      @param request The received HTTP request
      @param response Must be used to return the response
      @warning This method must be thread safe
    */
    virtual void service(HttpRequest &request, HttpResponse &response);

    /**
     * 접근 제어를 위한 권한 획득 함수
     * @param request The received HTTP request
     * @param response Must be used to return the response
     * @return 권한 획득 성공/실패
     * @warning This method must be thread safe
     */
    virtual bool authorize(HttpRequest &request, HttpResponse &response);

    /**
     새로운 접속 요청이 들어온 경우 알림 수신
     * @param request The received HTTP request
     */
    Q_INVOKABLE virtual void newHttpConnectionIncomming(HttpRequest *request);

    /**
     * http 요청을 받았을때 알림 수신
     * @param request
     */
    Q_INVOKABLE virtual void newHttpRequestIncomming(HttpRequest *request);

    /**
     * http header 수신이 완료된 경우 알림 수신
     * @param request
     */
    Q_INVOKABLE virtual void httpRequestHeaderRecieved(HttpRequest *request);

    /**
     * 권환 획득 실패시 알림 수신
     * @param request
     */
    Q_INVOKABLE virtual void httpRequestAccessDenied(HttpRequest *request);

    /**
     * http body 수신 진행 상태 알림
     * @param request
     * @warning Body가 없는 경우 알림을 받지 않음
     */
    Q_INVOKABLE virtual void httpRequestBodyReceived(HttpRequest *request);

    /**
     * request가 취소 된경우 알림
     * @param request
     */
    Q_INVOKABLE virtual void httpRequestAborted(HttpRequest *request);

    /**
     * http request timeout 알림
     * @param request
     */
    Q_INVOKABLE virtual void httpRequestTimeout(HttpRequest *request);

    /**
     * Http request의 Header와 Body를 모두 수신받고 파싱 완료 알림
     * @param request
     */
    Q_INVOKABLE virtual void httpRequestCompleted(HttpRequest *request);

    /**
     * http request에 대한 response 까지모두 완료 함
     * @param request
     */
    Q_INVOKABLE virtual void httpRequestFinished(HttpRequest *request);

    /**
     * 이전 요청에 대한 request가 모두 정리 되지 않은경우 삭제 통보
     * @param request
     */
    Q_INVOKABLE virtual void httpRequestExpired(HttpRequest *request);
};

} // namespace stefanfrings

#endif // HTTPREQUESTHANDLER_H

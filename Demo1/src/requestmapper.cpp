/**
  @file
  @author Stefan Frings
*/

#include "requestmapper.h"
#include "controller/dumpcontroller.h"
#include "controller/fileuploadcontroller.h"
#include "controller/formcontroller.h"
#include "controller/sessioncontroller.h"
#include "controller/templatecontroller.h"
#include "filelogger.h"
#include "global.h"
#include "staticfilecontroller.h"
#include <QCoreApplication>

RequestMapper::RequestMapper(QObject *parent)
    : HttpRequestHandler(parent)
{
    qDebug("RequestMapper: created");
}

RequestMapper::~RequestMapper()
{
    qDebug("RequestMapper: deleted");
}

void RequestMapper::service(HttpRequest &request, HttpResponse &response)
{
    QByteArray path = request.getPath();
    qDebug("RequestMapper: path=%s", path.data());

    // For the following pathes, each request gets its own new instance of the related controller.

    if (path.startsWith("/dump"))
    {
        DumpController().service(request, response);
    }

    else if (path.startsWith("/template"))
    {
        TemplateController().service(request, response);
    }

    else if (path.startsWith("/form"))
    {
        FormController().service(request, response);
    }

    else if (path.startsWith("/file"))
    {
        FileUploadController().service(request, response);
    }

    else if (path.startsWith("/session"))
    {
        SessionController().service(request, response);
    }

    // All other pathes are mapped to the static file controller.
    // In this case, a single instance is used for multiple requests.
    else
    {
        staticFileController->service(request, response);
    }

    qDebug("RequestMapper: finished request");

    // Clear the log buffer
    if (logger)
    {
        logger->clear();
    }
}

bool RequestMapper::authorize(HttpRequest &request, HttpResponse &response)
{
    auto receivedSize = request.getReceiveBodySize();
    auto expectedSize = request.getHeader("content-length").toInt();
    qDebug() << __FUNCTION__
             << QString("Request [%1] - IP: %2, STATUS :%3, PATH: %4, RECV: %5, ContentLength: %6")
                    .arg(reinterpret_cast<uint64_t>(&request))
                    .arg(request.getPeerAddress().toString())
                    .arg(static_cast<int32_t>(request.getStatus()))
                    .arg(QString(request.getPath()))
                    .arg(receivedSize)
                    .arg(expectedSize);

    return true;
}

void RequestMapper::newHttpConnectionIncomming(HttpRequest *request)
{
    if (request)
    {
        auto receivedSize = request->getReceiveBodySize();
        auto expectedSize = request->getHeader("content-length").toInt();
        qDebug() << __FUNCTION__
                 << QString("Request [%1] - IP: %2, STATUS :%3, PATH: %4, RECV: %5, ContentLength: %6")
                        .arg(reinterpret_cast<uint64_t>(&request))
                        .arg(request->getPeerAddress().toString())
                        .arg(static_cast<int32_t>(request->getStatus()))
                        .arg(QString(request->getPath()))
                        .arg(receivedSize)
                        .arg(expectedSize);
    }
    else
    {
        qDebug() << __FUNCTION__;
    }
}

void RequestMapper::newHttpRequestIncomming(HttpRequest *request)
{
    if (request)
    {
        auto receivedSize = request->getReceiveBodySize();
        auto expectedSize = request->getHeader("content-length").toInt();
        qDebug() << __FUNCTION__
                 << QString("Request [%1] - IP: %2, STATUS :%3, PATH: %4, RECV: %5, ContentLength: %6")
                        .arg(reinterpret_cast<uint64_t>(&request))
                        .arg(request->getPeerAddress().toString())
                        .arg(static_cast<int32_t>(request->getStatus()))
                        .arg(QString(request->getPath()))
                        .arg(receivedSize)
                        .arg(expectedSize);
    }
    else
    {
        qDebug() << __FUNCTION__;
    }
}

void RequestMapper::httpRequestHeaderRecieved(HttpRequest *request)
{
    if (request)
    {
        auto receivedSize = request->getReceiveBodySize();
        auto expectedSize = request->getHeader("content-length").toInt();
        qDebug() << __FUNCTION__
                 << QString("Request [%1] - IP: %2, STATUS :%3, PATH: %4, RECV: %5, ContentLength: %6")
                        .arg(reinterpret_cast<uint64_t>(&request))
                        .arg(request->getPeerAddress().toString())
                        .arg(static_cast<int32_t>(request->getStatus()))
                        .arg(QString(request->getPath()))
                        .arg(receivedSize)
                        .arg(expectedSize);
    }
    else
    {
        qDebug() << __FUNCTION__;
    }
}

void RequestMapper::httpRequestAccessDenied(HttpRequest *request)
{
    if (request)
    {
        auto receivedSize = request->getReceiveBodySize();
        auto expectedSize = request->getHeader("content-length").toInt();
        qDebug() << __FUNCTION__
                 << QString("Request [%1] - IP: %2, STATUS :%3, PATH: %4, RECV: %5, ContentLength: %6")
                        .arg(reinterpret_cast<uint64_t>(&request))
                        .arg(request->getPeerAddress().toString())
                        .arg(static_cast<int32_t>(request->getStatus()))
                        .arg(QString(request->getPath()))
                        .arg(receivedSize)
                        .arg(expectedSize);
    }
    else
    {
        qDebug() << __FUNCTION__;
    }
}

void RequestMapper::httpRequestBodyReceived(HttpRequest *request)
{
    if (request)
    {
        auto receivedSize = request->getReceiveBodySize();
        auto expectedSize = request->getHeader("content-length").toInt();
        qDebug() << __FUNCTION__
                 << QString("Request [%1] - IP: %2, STATUS :%3, PATH: %4, RECV: %5, ContentLength: %6")
                        .arg(reinterpret_cast<uint64_t>(&request))
                        .arg(request->getPeerAddress().toString())
                        .arg(static_cast<int32_t>(request->getStatus()))
                        .arg(QString(request->getPath()))
                        .arg(receivedSize)
                        .arg(expectedSize);
    }
    else
    {
        qDebug() << __FUNCTION__;
    }
}

void RequestMapper::httpRequestAborted(HttpRequest *request)
{
    if (request)
    {
        auto receivedSize = request->getReceiveBodySize();
        auto expectedSize = request->getHeader("content-length").toInt();
        qDebug() << __FUNCTION__
                 << QString("Request [%1] - IP: %2, STATUS :%3, PATH: %4, RECV: %5, ContentLength: %6")
                        .arg(reinterpret_cast<uint64_t>(&request))
                        .arg(request->getPeerAddress().toString())
                        .arg(static_cast<int32_t>(request->getStatus()))
                        .arg(QString(request->getPath()))
                        .arg(receivedSize)
                        .arg(expectedSize);
    }
    else
    {
        qDebug() << __FUNCTION__;
    }
}

void RequestMapper::httpRequestTimeout(HttpRequest *request)
{
    if (request)
    {
        auto receivedSize = request->getReceiveBodySize();
        auto expectedSize = request->getHeader("content-length").toInt();
        qDebug() << __FUNCTION__
                 << QString("Request [%1] - IP: %2, STATUS :%3, PATH: %4, RECV: %5, ContentLength: %6")
                        .arg(reinterpret_cast<uint64_t>(&request))
                        .arg(request->getPeerAddress().toString())
                        .arg(static_cast<int32_t>(request->getStatus()))
                        .arg(QString(request->getPath()))
                        .arg(receivedSize)
                        .arg(expectedSize);
    }
    else
    {
        qDebug() << __FUNCTION__;
    }
}

void RequestMapper::httpRequestCompleted(HttpRequest *request)
{
    if (request)
    {
        auto receivedSize = request->getReceiveBodySize();
        auto expectedSize = request->getHeader("content-length").toInt();
        qDebug() << __FUNCTION__
                 << QString("Request [%1] - IP: %2, STATUS :%3, PATH: %4, RECV: %5, ContentLength: %6")
                        .arg(reinterpret_cast<uint64_t>(&request))
                        .arg(request->getPeerAddress().toString())
                        .arg(static_cast<int32_t>(request->getStatus()))
                        .arg(QString(request->getPath()))
                        .arg(receivedSize)
                        .arg(expectedSize);
    }
    else
    {
        qDebug() << __FUNCTION__;
    }
}

void RequestMapper::httpRequestFinished(HttpRequest *request)
{
    if (request)
    {
        auto receivedSize = request->getReceiveBodySize();
        auto expectedSize = request->getHeader("content-length").toInt();
        qDebug() << __FUNCTION__
                 << QString("Request [%1] - IP: %2, STATUS :%3, PATH: %4, RECV: %5, ContentLength: %6")
                        .arg(reinterpret_cast<uint64_t>(&request))
                        .arg(request->getPeerAddress().toString())
                        .arg(static_cast<int32_t>(request->getStatus()))
                        .arg(QString(request->getPath()))
                        .arg(receivedSize)
                        .arg(expectedSize);
    }
    else
    {
        qDebug() << __FUNCTION__;
    }
}

void RequestMapper::httpRequestExpired(HttpRequest *request)
{
    if (request)
    {
        auto receivedSize = request->getReceiveBodySize();
        auto expectedSize = request->getHeader("content-length").toInt();
        qDebug() << __FUNCTION__
                 << QString("Request [%1] - IP: %2, STATUS :%3, PATH: %4, RECV: %5, ContentLength: %6")
                        .arg(reinterpret_cast<uint64_t>(&request))
                        .arg(request->getPeerAddress().toString())
                        .arg(static_cast<int32_t>(request->getStatus()))
                        .arg(QString(request->getPath()))
                        .arg(receivedSize)
                        .arg(expectedSize);
    }
    else
    {
        qDebug() << __FUNCTION__;
    }
}

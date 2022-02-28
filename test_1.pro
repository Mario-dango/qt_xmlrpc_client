QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    xmlrpc/XmlRpcClient.cpp \
    xmlrpc/XmlRpcDispatch.cpp \
    xmlrpc/XmlRpcServer.cpp \
    xmlrpc/XmlRpcServerConnection.cpp \
    xmlrpc/XmlRpcServerMethod.cpp \
    xmlrpc/XmlRpcSocket.cpp \
    xmlrpc/XmlRpcSource.cpp \
    xmlrpc/XmlRpcUtil.cpp \
    xmlrpc/XmlRpcValue.cpp \
    xmlrpc/cliente.cpp

HEADERS += \
    cliente.h \
    mainwindow.h \
    xmlrpc/XmlRpc.h \
    xmlrpc/XmlRpcClient.h \
    xmlrpc/XmlRpcDispatch.h \
    xmlrpc/XmlRpcException.h \
    xmlrpc/XmlRpcServer.h \
    xmlrpc/XmlRpcServerConnection.h \
    xmlrpc/XmlRpcServerMethod.h \
    xmlrpc/XmlRpcSocket.h \
    xmlrpc/XmlRpcSource.h \
    xmlrpc/XmlRpcUtil.h \
    xmlrpc/XmlRpcValue.h \
    xmlrpc/base64.h \
    xmlrpc/cliente.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    test_1_es_AR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

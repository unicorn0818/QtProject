QT       += core gui xml sql network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.D
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += E:\QT\qtcreator\5.14.2\mingw73_32\include\qtsoap.h
LIBS += E:\QT\qtcreator\5.14.2\mingw73_32\lib\QtSolutions_SOAP-head.dll
SOURCES += \
    analysissql.cpp \
    analysisxml.cpp \
    main.cpp \
    mainwin.cpp \
    qtsoap.cpp \
    submitreport.cpp

HEADERS += \
    analysissql.h \
    analysisxml.h \
    mainwin.h \
    qtsoap.h \
    submitreport.h

FORMS += \
    mainwin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    image/1.png

RESOURCES += \
    image.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2018-09-29T14:42:33
#
#-------------------------------------------------

QT += xlsx
QT += core gui
QT += serialport
QT +=printsupport
QT +=network
QT +=axcontainer

RC_ICONS += i4.ico
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
VERSION = 1.0
TARGET = S6300
INCLUDEPATH+=E:\WpdPack\Include
LIBS+=E:/WpdPack/Lib/x64/wpcap.lib
LIBS+=E:/WpdPack/Lib/x64/Packet.lib
#LIBS += wpcap.lib Packet.lib
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    config_set.cpp \
    customplothasroll.cpp \
    key_board_dlg.cpp \
    m_base_out.cpp \
    m_checkbox.cpp \
    m_spinbox.cpp \
    mainwindow.cpp \
    net_connect.cpp \
    serialex.cpp \
    xl803.cpp \
    QCustomPlot/qcustomplot.cpp \
    list_out.cpp \
    active_wave.cpp \
    statu_list.cpp \
    map_control.cpp

HEADERS  += \
    config_set.h \
    customplothasroll.h \
    key_board_dlg.h \
    m_base_out.h \
    m_checkbox.h \
    m_spinbox.h \
    mainwindow.h \
    net_connect.h \
    serialex.h \
    xl803.h \
    QCustomPlot/qcustomplot.h \
    list_out.h \
    active_wave.h \
    statu_list.h \
    map_control.h

FORMS    += \
    config_set.ui \
    key_board_dlg.ui \
    m_base_out.ui \
    mainwindow.ui \
    list_out.ui \
    active_wave.ui \
    statu_list.ui \
    map_control.ui

RESOURCES += \
    res.qrc

DISTFILES +=


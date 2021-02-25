#-------------------------------------------------
#
# Project created by QtCreator 2018-08-21T10:23:58
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       +=printsupport
QT       +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
INCLUDEPATH+=E:\WpdPack\Include

#LIBS+=E:/WpdPack/Lib/x64/wpcap.lib
#LIBS+=E:/WpdPack/Lib/x64/Packet.lib
LIBS+=F:\w_project\XL3216\wpcap.lib
LIBS+=F:\w_project\XL3216\Packet.lib
#LIBS+=Packet.lib wpcap.lib
RC_ICONS += xl.ico
TARGET = xl3216
TEMPLATE = app
VERSION = 2.2.1.0
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
#QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO
SOURCES += main.cpp\
        mainwindow.cpp \
    serialex.cpp \
    xl803.cpp \
    QCustomPlot/qcustomplot.cpp \
    customplothasroll.cpp \
    m_base_out.cpp \
    config_set.cpp \
    key_board_dlg.cpp \
    m_spinbox.cpp \
    hrenter_out.cpp \
    any_wave.cpp \
    active_wave.cpp \
    adjust_energy.cpp \
    m_checkbox.cpp \
    net_connect.cpp \
    reout_wave.cpp \
    XL-Comtrade/comtrade.cpp \
    map_control.cpp \
    ue_protocol.cpp \
    wave_reout.cpp \
    power_test.cpp \
    test_bll.cpp

HEADERS  += mainwindow.h \
    serialex.h \
    xl803.h \
    QCustomPlot/qcustomplot.h \
    customplothasroll.h \
    m_base_out.h \
    config_set.h \
    key_board_dlg.h \
    m_spinbox.h \
    hrenter_out.h \
    any_wave.h \
    active_wave.h \
    adjust_energy.h \
    m_checkbox.h \
    net_connect.h \
    reout_wave.h \
    XL-Comtrade/comtrade.h \
    XL-Comtrade/dataType.h \
    XL-Comtrade/Interpolation.h \
    XL-Comtrade/Lagrange.h \
    XL-Comtrade/stringtool.h \
    map_control.h \
    ue_protocol.h \
    wave_reout.h \
    power_test.h \
    test_bll.h \
    setdebugnew.h

FORMS    += mainwindow.ui \
    m_base_out.ui \
    config_set.ui \
    key_board_dlg.ui \
    hrenter_out.ui \
    any_wave.ui \
    active_wave.ui \
    adjust_energy.ui \
    reout_wave.ui \
    map_control.ui \
    wave_reout.ui \
    power_test.ui \
    test_bll.ui

DISTFILES +=

RESOURCES += \
    style.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2016-04-19T20:07:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MineSweeper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    minecell.cpp \
    minetable.cpp

HEADERS  += mainwindow.h \
    minecell.h \
    minetable.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

DISTFILES +=

RC_FILE = icon.rc

#-------------------------------------------------
#
# Project created by QtCreator 2016-03-14T18:39:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = raster_graphics
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    opencv_drawer.cpp

HEADERS  += mainwindow.h \
    opencv_drawer.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include/opencv
INCLUDEPATH += /usr/local/include/opencv2
LIBS += -L/usr/local/lib/ -lopencv_core -lopencv_imgproc -lopencv_imgcodecs


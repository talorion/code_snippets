#-------------------------------------------------
#
# Project created by QtCreator 2015-08-21T09:30:29
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = qt_threading
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    timed_thread.cpp \
    worker.cpp \
    reusable_thread.cpp

HEADERS += \
    timed_thread.h \
    worker.h \
    reusable_thread.h

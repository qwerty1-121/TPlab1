QT += core
QT -= gui

CONFIG += console c++17
CONFIG -= app_bundle

TEMPLATE = app
TARGET = FileWatcher

SOURCES += main.cpp \
           FileState.cpp

HEADERS += FileState.h
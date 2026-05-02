QT += core
QT -= gui

CONFIG += console c++17
CONFIG -= app_bundle

TEMPLATE = app
TARGET = FileWatcher

SOURCES += main.cpp \
           FileState.cpp \
           FileMonitor.cpp \
           ConsoleNotifier.cpp

HEADERS += FileState.h \
           FileMonitor.h \
           ConsoleNotifier.h
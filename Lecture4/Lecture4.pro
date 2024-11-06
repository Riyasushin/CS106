TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        macros.cpp \
        main.cpp

DISTFILES += \
    notes.md

HEADERS += \
    color.h \
    macros.h

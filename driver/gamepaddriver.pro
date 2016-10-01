TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lboost_serialization -lboost_system -lX11 -lXtst

SOURCES += main.cpp \
    GamepadDriver.cpp \
    GamepadData.cpp \
    LinuxFunctions.cpp \
    GamepadSettings.cpp \
    uniplatformfunctions.cpp

HEADERS += \
    GamepadDriver.h \
    GamepadData.h \
    LinuxFunctions.h \
    LinuxConstants.h \
    GamepadSettings.h \
    UniplatformConstants.h \
    UniplatformFunctions.h \
    Point2D.h \
    Presets.h

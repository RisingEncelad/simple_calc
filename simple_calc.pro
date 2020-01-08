TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Node.cpp \
        Operations.cpp \
        RPN.cpp \
        main.cpp

HEADERS += \
    Node.h \
    Operations.h \
    RPN.h \
    test_framework.h

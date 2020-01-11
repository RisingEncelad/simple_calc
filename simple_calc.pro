TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Node.cpp \
        Operations.cpp \
        RPN.cpp \
        main.cpp \
        test_math_functions.cpp \
        test_parsers.cpp

HEADERS += \
    MathFunctions.h \
    Node.h \
    Operations.h \
    RPN.h \
    test_framework.h \
    test_functions.h

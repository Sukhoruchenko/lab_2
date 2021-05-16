TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        CPlusPlus.cpp \
        CSharp.cpp \
        ClassUnit.cpp \
        Generate.cpp \
        Generation.cpp \
        Java.cpp \
        MethodUnit.cpp \
        PrintOperatorUnit.cpp \
        Unit.cpp \
        main.cpp

HEADERS += \
    CPlusPlus.h \
    CSharp.h \
    ClassUnit.h \
    Generate.h \
    Generation.h \
    Java.h \
    MethodUnit.h \
    PrintOperatorUnit.h \
    Unit.h

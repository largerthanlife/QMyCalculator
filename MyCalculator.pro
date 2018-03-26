#-------------------------------------------------
#
# Project created by QtCreator 2018-03-23T00:03:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyCalculator
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    bodh_conversion.cpp \
    equation.cpp \
    evaluate_expression.cpp \
    operate.cpp \
    precede.cpp \
    show.cpp \
    stack.cpp \
    string_handle.cpp \
    string_to_oprand.cpp \
    variance.cpp \
    main.cpp

HEADERS  += mainwindow.h \
    calculator.h \
    stack.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

RC_FILE += ico.rc

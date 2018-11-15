# ***************************************************************************
# Copyright (c) 2013-2015, Simon Meaden
# ***************************************************************************
#
# Simonsoft - QWorkbook Library
# Config PRI File
#
# QWorkbook is intended as a simple spreadsheet based on QTableView.
#
# This code is licensed under the GPL Version 3.0
# ***************************************************************************

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += $$PWD

SOURCES += \
    collection.cpp \
    comment.cpp \
    emitter.cpp \
    node.cpp \
    parse.cpp

HEADERS +=  \
    parse.h \
    collection.h \
    comment.h \
    emitter.h \
    node.h

DISTFILES += \
    qyaml-cpp.h \
    QYamlCpp

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
QT += xlsx

INCLUDEPATH += $$PWD

SOURCES += \
    collection.cpp \
    comment.cpp \
    emitter.cpp \
    node.cpp

HEADERS += \
    collection.h \
    comment.h \
    emitter.h \
    node.h \
    qyaml-cpp.h \
    QYamlCpp

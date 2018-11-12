#-------------------------------------------------
#
# Project created by QtCreator 2018-10-09T12:40:20
#
#-------------------------------------------------

QT       += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qyaml-cpp
TEMPLATE = lib

DEFINES += QYAMLCPP_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
TARGET = qyaml-cpp

include($$PWD/qyaml-cpp.pri)

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    README.md \
    qyaml-cpp.pri

# YAML-CPP
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../yaml-cpp/release/ -lyaml-cpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../yaml-cpp/debug/ -lyaml-cppd
else:unix: LIBS += -L$$OUT_PWD/../yaml-cpp/ -lyaml-cpp

INCLUDEPATH += $$PWD/../yaml-cpp/include
DEPENDPATH += $$PWD/../yaml-cpp/include
DEPENDPATH += $$PWD/../yaml-cpp/src

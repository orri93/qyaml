#-------------------------------------------------
#
# Project created by QtCreator 2016-09-02T10:51:50
#
#-------------------------------------------------

QT       -= gui

TARGET = qyaml
TEMPLATE = lib

DEFINES += QYAML_LIBRARY

#CONFIG += debug_and_release_target
CONFIG += static # static library
CONFIG += c++11 # C++11 is the newest standard

DESTDIR = ../../build/qyaml

CONFIG(debug, debug|release) {
    TARGET = qyamld
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.mocd
    RCC_DIR = $$DESTDIR/.qrcd
    UI_DIR = $$DESTDIR/.uid
}

CONFIG(release, debug|release) {
    TARGET = qyaml
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.moc
    RCC_DIR = $$DESTDIR/.qrc
    UI_DIR = $$DESTDIR/.ui
}

include(qyaml.pri)

unix {
    target.path = /usr/lib
    INSTALLS += target
}


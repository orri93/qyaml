INCLUDEPATH += $$PWD

SOURCES += \
    $$PWD/collection.cpp \
    $$PWD/comment.cpp \
    $$PWD/emitter.cpp \
    $$PWD/node.cpp

HEADERS += \
    $$PWD/qyaml.h \
    $$PWD/collection.h \
    $$PWD/comment.h \
    $$PWD/emitter.h \
    $$PWD/node.h

unix|win32: LIBS += -lyaml-cpp

DISTFILES += \
    qyaml.pri \
    $$PWD/../README.md

#-------------------------------------------------
#
# Project created by QtCreator 2021-11-25T10:09:02
#
#-------------------------------------------------

QT       += core gui\
            multimedia\
            network widgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Asteroids
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    bullet.cpp \
    rocks.cpp \
    Score.cpp \
    Health.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    player.h \
    bullet.h \
    rocks.h \
    Score.h \
    Health.h \
    dialog.h


FORMS    += mainwindow.ui \
    dialog.ui


RESOURCES += \
    resource.qrc

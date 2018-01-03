#-------------------------------------------------
#
# Project created by QtCreator 2017-11-12T16:13:16
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DancingAlgorithms
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    main_window.cpp

HEADERS += \
    main_window.h \
    display/display_base.h \
    display/rect_item.h \
    display/search_base.h \
    config/bfs_c.h \
    config/dfs_c.h \
    config/single_linked_list_c.h \
    config/config_base.h \
    display/bfs_d.h \
    display/dfs_d.h \
    display/single_linked_list_d.h

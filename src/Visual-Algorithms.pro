#-------------------------------------------------
#
# Project created by QtCreator 2018-02-14T12:18:09
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Visual-Algorithms
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
        main_window.cpp \
    config/config_base.cpp \
    config/c_search_base.cpp \
    config/c_bfs.cpp \
    config/c_dfs.cpp \
    config/c_insert_sort.cpp \
    display/rect_item.cpp \
    display/d_search_base.cpp \
    display/display_base.cpp \
    display/d_bfs.cpp \
    display/d_dfs.cpp \
    display/d_insert_sort.cpp \
    config/c_single_linked_list.cpp \
    display/d_single_linked_list.cpp \
    display/line_item.cpp

HEADERS += \
        main_window.h \
    config/config_base.h \
    config/c_search_base.h \
    config/c_bfs.h \
    config/c_dfs.h \
    config/c_insert_sort.h \
    display/rect_item.h \
    display/d_search_base.h \
    display/display_base.h \
    display/d_bfs.h \
    display/d_dfs.h \
    display/d_insert_sort.h \
    config/c_single_linked_list.h \
    display/d_single_linked_list.h \
    display/line_item.h

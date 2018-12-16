#-------------------------------------------------
#
# Project created by QtCreator 2018-08-23 19:14:23
#
# Author
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Visual Algorithms
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

RC_ICONS = resources/app.ico

SOURCES += \
    src/main.cpp \
    src/main_window.cpp \
    src/widgets/option_dialog.cpp \
    src/widgets/message_dialog.cpp \
    src/widgets/tool_button.cpp \
    src/widgets/tree_widget.cpp \
    src/scenes/items/rect_item.cpp \
    src/scenes/base_scene.cpp \
    src/scenes/bfs_scene.cpp \
    src/panes/base_pane.cpp \
    src/panes/bfs_pane.cpp \
    src/scenes/searching_scene.cpp \
    src/objects/base_object.cpp \
    src/objects/bfs_object.cpp \
    src/objects/searching_object.cpp

HEADERS += \
    src/config.h \
    src/main_window.h \
    src/widgets/option_dialog.h \
    src/widgets/message_dialog.h \
    src/widgets/tool_button.h \
    src/widgets/tree_widget.h \
    src/scenes/items/rect_item.h \
    src/scenes/base_scene.h \
    src/scenes/bfs_scene.h \
    src/panes/bfs_pane.h \
    src/panes/base_pane.h \
    src/scenes/searching_scene.h \
    src/objects/base_object.h \
    src/objects/bfs_object.h \
    src/objects/searching_object.h

RESOURCES += \
    resources/res.qrc


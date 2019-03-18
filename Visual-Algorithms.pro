QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Visual Algorithms
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

RC_ICONS = image/app.ico

SOURCES += \
    src/main.cpp \
    src/main_window.cpp \
    src/widget/tool_button.cpp \
    src/widget/tree_widget.cpp \
    src/item/rect_item.cpp \
    src/scene/base_scene.cpp \
    src/scene/bfs_scene.cpp \
    src/pane/base_pane.cpp \
    src/pane/bfs_pane.cpp \
    src/scene/searching_scene.cpp \
    src/object/base_object.cpp \
    src/object/bfs_object.cpp \
    src/object/searching_object.cpp

HEADERS += \
    src/config.h \
    src/main_window.h \
    src/widget/tool_button.h \
    src/widget/tree_widget.h \
    src/item/rect_item.h \
    src/scene/base_scene.h \
    src/scene/bfs_scene.h \
    src/pane/bfs_pane.h \
    src/pane/base_pane.h \
    src/scene/searching_scene.h \
    src/object/base_object.h \
    src/object/bfs_object.h \
    src/object/searching_object.h

RESOURCES += \
    image/image.qrc


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Sorts/all_sorts.h \
    Sorts/libraries_and_namespaces.h \
    Sorts/merge_sort.h \
    Sorts/selection_sort.h \
    Sorts/sort_diagram.h \
    diagram_builder.h \
    mainwindow.h \
    my_graphics_view.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    lab2_en_GB.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

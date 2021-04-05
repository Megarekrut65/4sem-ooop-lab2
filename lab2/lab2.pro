QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutalgorithm.cpp \
    algorithms_efficiency_window.cpp \
    drawwindow.cpp \
    filepath.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Sorts/all_sorts.h \
    Sorts/bubble_sort.h \
    Sorts/cocktailshaker_sort.h \
    Sorts/comb_sort.h \
    Sorts/gnome_sort.h \
    Sorts/libraries_and_namespaces.h \
    Sorts/merge_sort.h \
    Sorts/odd_even_sort.h \
    Sorts/quick_sort.h \
    Sorts/selection_sort.h \
    aboutalgorithm.h \
    algorithms_efficiency_window.h \
    diagram_builder.h \
    drawwindow.h \
    filepath.h \
    mainwindow.h \
    memento_sorting.h \
    my_graphics_view.h \
    originator_sorting.h \
    sort_class.h

FORMS += \
    aboutalgorithm.ui \
    algorithms_efficiency_window.ui \
    drawwindow.ui \
    mainwindow.ui

TRANSLATIONS += \
    lab2_en_GB.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Images/about-icon.ico \
    Images/diagram-icon.ico \
    Images/main-icon.ico \
    Logs/sorting_diagram_log.txt

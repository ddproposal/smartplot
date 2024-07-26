QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

include($$PWD/SARibbon.pri)

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filedevice.cpp \
    main.cpp \
    mainwindow.cpp \
    mywidget.cpp \
    pwidget.cpp \
    showplot.cpp

HEADERS += \
    filedevice.h \
    mainwindow.h \
    mywidget.h \
    pwidget.h \
    showplot.h

FORMS += \
    forms/mainwindow.ui \
    forms/pwidget.ui

INCLUDEPATH += /usr/include/python3.10
LIBS += -L/usr/lib/python3.10/config-3.10-x86_64-linux-gnu -lpython3.10

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    svg.qrc \
    SARibbonBar/resource.qrc

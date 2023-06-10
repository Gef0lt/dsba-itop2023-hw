QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about_window.cpp \
    addnew.cpp \
    choosefield.cpp \
    chooseorder.cpp \
    choosetype.cpp \
    drawlogo.cpp \
    main.cpp \
    mainwindow.cpp \
    searchreq.cpp

HEADERS += \
    about_window.h \
    addnew.h \
    choosefield.h \
    chooseorder.h \
    choosetype.h \
    drawlogo.h \
    mainwindow.h \
    searchreq.h

FORMS += \
    about_window.ui \
    addnew.ui \
    choosefield.ui \
    chooseorder.ui \
    choosetype.ui \
    mainwindow.ui \
    searchreq.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc

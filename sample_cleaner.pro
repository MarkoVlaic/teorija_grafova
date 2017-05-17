TEMPLATE=app TARGET=sample_cleaner
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp \
    welcomewidget.cpp \
    manualinput.cpp \
    manualdialog.cpp \
    filedialog.cpp \
    snphandler.cpp \
    resultdisplay.cpp

HEADERS += \
    window.h \
    welcomewidget.h \
    manualinput.h \
    manualdialog.h \
    filedialog.h \
    snphandler.h \
    resultdisplay.h

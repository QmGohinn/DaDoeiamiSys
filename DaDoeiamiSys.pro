
##  ▼▼▼▼▼ 以下为自定义 ▼▼▼▼▼

## 添加Orm三方库
## 包含QxOrm模块的pri文件
include($$PWD/3rd/QxOrm/QxOrm.pri)

DEFINES += _BUILDING_APP

# 预编译头文件
!contains(DEFINES, _QX_NO_PRECOMPILED_HEADER) {
    PRECOMPILED_HEADER = src/_base/precompiled.h
}

#添加源代码的头文件路劲和链接库路径
INCLUDEPATH += $$PWD/3rd/QxOrm/include
LIBS += -L$$PWD/3rd/QxOrm/lib

DESTDIR = $$PWD/_output

## 根据编译环境不同链接不同的库并生成不同的程序
CONFIG(debug, debug|release) {
TARGET = DaDoeiamiSysD
LIBS += -lQxOrmd
} else {
TARGET = DaDoeiamiSys
LIBS += -lQxOrm
}

## ▲▲▲▲▲ *********** ▲▲▲▲▲

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/_APL/main/eiamisyswindows.cpp \
    src/_base/main.cpp


HEADERS += \
    src/_APL/main/eiamisyswindows.h \
    src/_base/export.h \
    src/_base/precompiled.h


FORMS += \
    src/_APL/main/eiamisyswindows.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Add Link Lib & DLL & a
DISTFILES += \
    3rd/QxOrm/lib/QxOrmd.dll \
    3rd/QxOrm/lib/libQxOrmd.a

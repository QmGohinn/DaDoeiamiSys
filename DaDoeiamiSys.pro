## 添加Orm三方库
##  ▼▼▼▼▼ 以下为自定义 ▼▼▼▼▼
#_BUILDING_USER，通过它可以知道项目是否正在编译
DEFINES += _BUILDING_APP

#包含模块的pri文件，一些宏定义使用中需要用到
include($$PWD/3rd/QxOrm/QxOrm.pri)

#添加源代码的头文件路劲，后面代码包含头文件的时候就可以使用相对路径了
INCLUDEPATH += $$PWD/3rd/QxOrm/include

#添加编译好的动态库，QxOrm源码编译的动态库在QxOrm/lib目录中，最好编译debug、release两个版本
LIBS += -L$$PWD/3rd/QxOrm/lib
## 根据编译环境不同链接不同的库
CONFIG(debug, debug|release) {
LIBS += -lQxOrmd
} else {
LIBS +=  -lQxOrm
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
    src/_APL/main/main.cpp


HEADERS += \
    src/_APL/main/eiamisyswindows.h


FORMS += \
    src/_APL/main/eiamisyswindows.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

## 配置输出目录
CONFIG(debug, debug|release){
    DESTDIR = $$PWD/_output/debug
}else{
    DESTDIR = $$PWD/_output/release
}

## 输出文件分类
build_type =
CONFIG(debug, debug|release) {
    build_type = debug
} else {
    build_type = release
}

DESTDIR     = $$build_type/out
OBJECTS_DIR = $$build_type/obj
MOC_DIR     = $$build_type/moc
RCC_DIR     = $$build_type/rcc
UI_DIR      = $$build_type/ui

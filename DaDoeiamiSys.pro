## 包含QxOrm模块和QsLog库的pri文件
include($$PWD/3rd/QxOrm/QxOrm.pri)
include($$PWD/3rd/QsLog/QsLog.pri)
include($$PWD/3rd/QXlsx/QXlsx.pri)

DEFINES += _BUILDING_APP

## 预编译头文件
!contains(DEFINES, _QX_NO_PRECOMPILED_HEADER) {
    PRECOMPILED_HEADER = src/_base/precompiled.h
}

## 添加QxOrm源代码的头文件路劲和链接库路径
INCLUDEPATH += $$PWD/3rd/QxOrm/include
LIBS += -L$$PWD/3rd/QxOrm/lib

## 设置输出目录
DESTDIR = $$PWD/_output

## 根据编译环境不同链接不同的库并生成不同的程序
CONFIG(debug, debug|release) {
TARGET = UVisionD
LIBS += -lQxOrmd
} else {
TARGET = UVision
LIBS += -lQxOrm
}

## 添加的Qt模块
QT       += core gui
QT       += sql
QT       += charts
QT       += xml
#QT       += webenginewidgets

## PSQL驱动
#INCLUDEPATH += "D:/psql/include"
#LIBS += "D:/psql/lib/libpq.lib"

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
    src/_APL/ChangePWD/changepwdform.cpp \
    src/_APL/ErrorPredict/errorpredictform.cpp \
    src/_APL/KindOfDevLog/kindofdevlogform.cpp \
    src/_APL/SelfCenter/selfcenterform.cpp \
    src/_APL/ShiftUser/shiftuserform.cpp \
    src/_APL/SimulateDataToolForm/simulatedatatoolform.cpp \
    src/_APL/SysSettings/syssettingsform.cpp \
    src/_APL/ThresholdSet/thresholdset.cpp \
    src/_APL/main/eiamisyswindows.cpp \
    src/_APL/regiuser/regiuserform.cpp \
    src/_APL/settingTime/timeset.cpp \
    src/_APL/settingYCode/ycodeset.cpp \
    src/_APL/userlogin/userloginform.cpp \
    src/_BK/AccountEnt/AccountEnt.cpp \
    src/_BK/BaseEnt/BaseEnt.cpp \
    src/_BK/BeltEnt/BeltEnt.cpp \
    src/_BK/BoilerEnt/BoilerEnt.cpp \
    src/_BK/InspectorEnt/InspectorEnt.cpp \
    src/_BK/LogEnt/LogEnt.cpp \
    src/_BK/MotorEnt/MotorEnt.cpp \
    src/_BK/PipelineEnt/PipelineEnt.cpp \
    src/_BK/TotalShow/TotalShow.cpp \
    src/_BK/TransformerEnt/TransformerEnt.cpp \
    src/_BK/UserLogEnt/UserLogEnt.cpp \
    src/_base/DBSetup.cpp \
    src/_base/SysInit.cpp \
    src/_base/UVConfigXmlHander.cpp \
    src/_base/UVGlobal.cpp \
    src/_base/UVThread.cpp \
    src/_base/main.cpp

HEADERS += \
    src/_APL/ChangePWD/changepwdform.h \
    src/_APL/ErrorPredict/errorpredictform.h \
    src/_APL/KindOfDevLog/kindofdevlogform.h \
    src/_APL/SelfCenter/selfcenterform.h \
    src/_APL/ShiftUser/shiftuserform.h \
    src/_APL/SimulateDataToolForm/simulatedatatoolform.h \
    src/_APL/SysSettings/syssettingsform.h \
    src/_APL/ThresholdSet/thresholdset.h \
    src/_APL/main/eiamisyswindows.h \
    src/_APL/regiuser/regiuserform.h \
    src/_APL/settingTime/timeset.h \
    src/_APL/settingYCode/ycodeset.h \
    src/_APL/userlogin/userloginform.h \
    src/_BK/AccountEnt/AccountEnt.h \
    src/_BK/BaseEnt/BaseEnt.h \
    src/_BK/BeltEnt/BeltEnt.h \
    src/_BK/BoilerEnt/BoilerEnt.h \
    src/_BK/InspectorEnt/InspectorEnt.h \
    src/_BK/LogEnt/LogEnt.h \
    src/_BK/MotorEnt/MotorEnt.h \
    src/_BK/PipelineEnt/PipelineEnt.h \
    src/_BK/TotalShow/TotalShow.h \
    src/_BK/TransformerEnt/TransformerEnt.h \
    src/_BK/UserLogEnt/UserLogEnt.h \
    src/_base/DBSetup.h \
    src/_base/SysInit.h \
    src/_base/UVConfigXmlHander.h \
    src/_base/UVGlobal.h \
    src/_base/UVThread.h \
    src/_base/dbTableReg.hpp \
    src/_base/export.h \
    src/_base/precompiled.h

FORMS += \
    src/_APL/ChangePWD/changepwdform.ui \
    src/_APL/ErrorPredict/errorpredictform.ui \
    src/_APL/KindOfDevLog/kindofdevlogform.ui \
    src/_APL/SelfCenter/selfcenterform.ui \
    src/_APL/ShiftUser/shiftuserform.ui \
    src/_APL/SimulateDataToolForm/simulatedatatoolform.ui \
    src/_APL/SysSettings/syssettingsform.ui \
    src/_APL/ThresholdSet/thresholdset.ui \
    src/_APL/main/eiamisyswindows.ui \
    src/_APL/regiuser/regiuserform.ui \
    src/_APL/settingTime/timeset.ui \
    src/_APL/settingYCode/ycodeset.ui \
    src/_APL/userlogin/userloginform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Add Link Lib & DLL & a
DISTFILES += \
    .gitignore \
    3rd/QsLog/lib/QsLog2.dll \
    3rd/QxOrm/lib/QxOrm.dll \
    3rd/QxOrm/lib/QxOrmd.dll \
    HELP.txt \
    README.md \
    bat/fix.bat \
    config/cfg.xml \
    doc/中间文档/uvision.xlsx \
    doc/交付物/开题报告.doc \
    doc/交付物/文献综述.doc \
    doc/交付物/文献翻译.doc \
    doc/打印.zip \
    doc/打印/任务书.doc \
    doc/打印/开题报告.docx \
    doc/打印/文献综述.docx \
    doc/打印/文献翻译.docx \
    doc/打印/毕业设计档案袋封皮.docx \
    doc/提供物/企业巡检分析管理信息系统设计与开发-任务书-吴斌.docx \
    doc/提供物/关于做好2022届本科毕业设计（论文）工作的通知.doc \
    doc/提供物/开题报告.doc \
    doc/提供物/文献综述.doc \
    doc/提供物/文献翻译.doc \
    doc/提供物/题目.txt \
    doc/版本文档/开题报告.doc \
    doc/版本文档/开题报告初版.doc \
    doc/版本文档/文献综述.doc \
    doc/版本文档/文献翻译.doc \
    res/tab/editable.ico

## 程序LOGO
RC_ICONS += res/logo/exelogo.ico

# 分类存放输出文件
build_type =
CONFIG(debug, debug|release) {
    build_type = debug
} else {
    build_type = release
}

## 输出目录分类
DESTDIR     = $$build_type/exe
OBJECTS_DIR = $$build_type/obj
MOC_DIR     = $$build_type/moc
RCC_DIR     = $$build_type/rcc
UI_DIR      = $$build_type/ui

## Res File
RESOURCES += \
    Resource.qrc

CONFIG += QMAKE_CXXFLAGS_WARN_OFF

#ifndef UVGLOBAL_H
#define UVGLOBAL_H

#include <QMap>
#include <QVector>
#include <QString>

class UVGlobal
{
public:
    UVGlobal();
    ~UVGlobal();

public:
    static void init();
    static QMap<int, QString> g_mapIntQStr;
};

#endif // UVGLOBAL_H

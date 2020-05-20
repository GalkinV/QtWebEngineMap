#include "webclass.h"
#include <QMessageBox>
#include <QDebug>

WebClass::WebClass(QObject *parent) : QObject(parent)
{

}


void WebClass::catchJsWkt(QString wkt)
{
    //qDebug()<< wkt;
    emit wktToQt(wkt);

}

void WebClass::catchQtWkt(QString wkt)
{
    //qDebug()<< wkt;
    emit wktToJS(wkt);

}

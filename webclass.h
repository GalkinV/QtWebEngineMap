#ifndef WEBCLASS_H
#define WEBCLASS_H

#include <QObject>

class WebClass : public QObject
{
    Q_OBJECT
public:
    explicit WebClass(QObject *parent = nullptr);

signals:
    void wktToJS(QString value);
    void wktToQt(QString value);

public slots:
    void catchJsWkt(QString wkt);
    void catchQtWkt(QString wkt);
};

#endif // WEBCLASS_H

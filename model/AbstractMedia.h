#ifndef ABSTRACTMEDIA_H
#define ABSTRACTMEDIA_H

#include <QString>
#include <QJsonObject>
#include <QJsonValue>
#include "MediaVisitor.h"

class AbstractMedia {

public:
    AbstractMedia(unsigned int id, QString title, unsigned int year, QString descr, QString imgUrl);
    AbstractMedia(AbstractMedia& m);

    unsigned int getId() const;
    QString getTitle() const;
    unsigned int getYear() const;
    QString getDescr() const;
    QString getImg() const;

    void setId(unsigned int);
    void setTitle(QString title);
    void setYear(unsigned int year);
    void setDescr(QString descr);
    void setImg(QString img);

    virtual void accept(MediaVisitor *visitor) = 0;
    virtual void acceptEdit(MediaVisitor *visitor) = 0;

    // virtual QJsonObject toJson() const = 0;

protected:
    unsigned int id;
    QString title;
    unsigned int year;
    QString description;
    QString imgUrl;
};

#endif

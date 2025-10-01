#ifndef ARTICLE_H
#define ARTICLE_H

#include "AbstractMedia.h"

class Article : public AbstractMedia {
public:
    Article(unsigned int id, QString title, unsigned int year, QString descr, QString imgUrl, QString author, QString magazine);
    Article(Article& a);

    QString getAuthor() const;
    QString getMagazine() const;

    void setAuthor(QString author);
    void setMagazine(QString mag);

    virtual void accept(MediaVisitor *visitor);
    virtual void acceptEdit(MediaVisitor *visitor);

    // virtual QJsonObject toJson() const;

private:
    QString author;
    QString magazine;
};

#endif

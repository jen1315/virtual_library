#ifndef BOOK_H
#define BOOK_H

#include "AbstractMedia.h"

class Book : public AbstractMedia {
public:
    Book(unsigned int id, QString title, unsigned int year, QString descr, QString imgUrl, QString author, QString lang);
    Book(Book& b);

    QString getAuthor() const;
    QString getLanguage() const;

    void setAuthor(QString author);
    void setLanguage(QString lang);

    virtual void accept(MediaVisitor *visitor);
    virtual void acceptEdit(MediaVisitor *visitor);

    // virtual QJsonObject toJson() const;

private:
    QString author;
    QString language;
};

#endif

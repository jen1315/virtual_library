#ifndef FILM_H
#define FILM_H

#include "AbstractMedia.h"

class Film : public AbstractMedia {
public:
    Film(unsigned int id, QString name, unsigned int year, QString descr, QString imgUrl, QString director, unsigned int tot_min);
    Film(Film& f);

    QString getDirector() const;
    unsigned int getHours() const;
    unsigned int getMinutes() const;

    void setDirector(QString director);
    void setTotMinutes(unsigned int tot_min);

    virtual void accept(MediaVisitor *visitor);
    virtual void acceptEdit(MediaVisitor *visitor);

    // virtual QJsonObject toJson() const;

private:
    QString director;
    unsigned int tot_minutes;
};

#endif

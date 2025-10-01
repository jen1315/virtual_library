#include "Film.h"

Film::Film(unsigned int id, QString title, unsigned int year, QString descr, QString imgUrl, QString director, unsigned int tot_min) : AbstractMedia(id, title, year, descr, imgUrl), director(director), tot_minutes(tot_min) {}

Film::Film(Film& f) : AbstractMedia(f), director(f.director), tot_minutes(f.tot_minutes) {}

QString Film::getDirector() const {
    return director;
}

unsigned int Film::getHours() const {
    return tot_minutes/60;
}

unsigned int Film::getMinutes() const {
    return tot_minutes-((Film::getHours())*60);
}

void Film::setDirector(QString director) {
    this->director = director;
}

void Film::setTotMinutes(unsigned int tot_min) {
    this->tot_minutes = tot_min;
}

void Film::accept(MediaVisitor *visitor) {
    visitor->visit(this);
}

void Film::acceptEdit(MediaVisitor *visitor) {
    visitor->visitEdit(this);
}

/*QJsonObject Film::toJson() const {
    QJsonObject obj;
    obj.insert("id", QJsonValue::fromVariant(id));
    obj.insert("title", QJsonValue::fromVariant(title));
    obj.insert("year", QJsonValue::fromVariant(year));
    obj.insert("descr", QJsonValue::fromVariant(description));
    obj.insert("imgUrl", QJsonValue::fromVariant(imgUrl));
    obj.insert("director", QJsonValue::fromVariant(director));
    obj.insert("tot_minutes", QJsonValue::fromVariant(tot_minutes));
    obj.insert("type", QJsonValue::fromVariant("film"));

    return obj;
}*/

#include "AbstractMedia.h"

AbstractMedia::AbstractMedia(unsigned int id, QString title, unsigned int year, QString descr, QString imgUrl) : id(id), title(title), year(year), description(descr), imgUrl(imgUrl) {}

AbstractMedia::AbstractMedia(AbstractMedia& m) : title(m.title), year(m.year), description(m.description), imgUrl(m.imgUrl) {};

unsigned int AbstractMedia::getId() const {
    return id;
}

QString AbstractMedia::getTitle() const {
    return title;
}

unsigned int AbstractMedia::getYear() const {
    return year;
}

QString AbstractMedia::getDescr() const {
    return description;
}

QString AbstractMedia::getImg() const {
    return imgUrl;
}

void AbstractMedia::setId(unsigned int) {
    this->id = id;
}

void AbstractMedia::setTitle(QString title) {
    this->title = title;
}

void AbstractMedia::setYear(unsigned int year){
    this->year = year;
}

void AbstractMedia::setDescr(QString descr){
    this->description = descr;
}

void AbstractMedia::setImg(QString img) {
    this->imgUrl = img;
}

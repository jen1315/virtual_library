#include "Article.h"

Article::Article(unsigned int id, QString title, unsigned int year, QString descr, QString imgUrl, QString author, QString mag) : AbstractMedia(id, title, year, descr, imgUrl), author(author),  magazine(mag) {}
    
Article::Article(Article& a): AbstractMedia(a), author(a.author), magazine(a.magazine) {}

QString Article::getAuthor() const {
    return author;
}

QString Article::getMagazine() const {
    return magazine;
}

void Article::setAuthor(QString author) {
    this->author = author;
}

void Article::setMagazine(QString mag) {
    this->magazine = mag;
}

void Article::accept(MediaVisitor *visitor) {
    visitor->visit(this);
}

void Article::acceptEdit(MediaVisitor *visitor) {
    visitor->visitEdit(this);
}

/*QJsonObject Article::toJson() const {
    QJsonObject obj;
    obj.insert("id", QJsonValue::fromVariant(id));
    obj.insert("title", QJsonValue::fromVariant(title));
    obj.insert("year", QJsonValue::fromVariant(year));
    obj.insert("descr", QJsonValue::fromVariant(description));
    obj.insert("imgUrl", QJsonValue::fromVariant(imgUrl));
    obj.insert("author", QJsonValue::fromVariant(author));
    obj.insert("magazine", QJsonValue::fromVariant(magazine));
    obj.insert("type", QJsonValue::fromVariant("article"));

    return obj;
}*/

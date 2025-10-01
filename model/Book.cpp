#include "Book.h"

Book::Book(unsigned int id, QString title, unsigned int year, QString descr, QString imgUrl, QString author, QString lang) : AbstractMedia(id, title, year, descr, imgUrl), author(author), language(lang) {}

Book::Book(Book& b) : AbstractMedia(b), author(b.author), language(b.language) {}

QString Book::getAuthor() const {
    return author;
}

QString Book::getLanguage() const {
    return language;
}

void Book::setAuthor(QString author) {
    this->author = author;
}

void Book::setLanguage(QString lang) {
    this->language = lang;
}

void Book::accept(MediaVisitor *visitor) {
    visitor->visit(this);
}

void Book::acceptEdit(MediaVisitor *visitor) {
    visitor->visitEdit(this);
}

/*QJsonObject Book::toJson() const {
    QJsonObject obj;
    obj.insert("id", QJsonValue::fromVariant(id));
    obj.insert("title", QJsonValue::fromVariant(title));
    obj.insert("year", QJsonValue::fromVariant(year));
    obj.insert("descr", QJsonValue::fromVariant(description));
    obj.insert("imgUrl", QJsonValue::fromVariant(imgUrl));
    obj.insert("author", QJsonValue::fromVariant(author));
    obj.insert("language", QJsonValue::fromVariant(language));
    obj.insert("type", QJsonValue::fromVariant("book"));

    return obj;
}*/

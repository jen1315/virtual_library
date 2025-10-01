#include "JsonFile.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "./model/Book.h"
#include "./model/Film.h"
#include "./model/Article.h"

JsonFile::JsonFile(const QString jsonUrl) {
    file = new QFile(jsonUrl);
    lib = new QMap<int, AbstractMedia*>();
    if(!file->open(QIODevice::ReadOnly)) {
        qDebug("Errore di caricamento.");
    }
    
    QByteArray data = file->readAll();
    file->close();
    
    QJsonDocument json = QJsonDocument::fromJson(data);
    if(!json.isArray()) {
        qDebug("Errore di caricamento.");
    }
    
    QJsonArray array = json.array();
    
    for(auto it=array.begin(); it!=array.end(); ++it) {
        QJsonObject obj = it->toObject();

        QString type = obj["type"].toString();
        int id = obj["id"].toInt();
        QString title = obj["title"].toString();
        int year = obj["year"].toInt();
        QString descr = obj["descr"].toString();
        QString img = obj["imgUrl"].toString();

        AbstractMedia *media;

        if(type=="book")
            media = new Book(id, title, year, descr, img, obj["author"].toString(), obj["language"].toString());
        if(type=="film")
            media = new Film(id, title, year, descr, img, obj["director"].toString(), obj["tot_minutes"].toInt());
        if(type=="article")
            media = new Article(id, title, year, descr, img, obj["author"].toString(), obj["magazine"].toString());
        lib->insert(id, media);
    }
}

QMap<int, AbstractMedia*>& JsonFile::getMap() const {
    return *lib;
}

void JsonFile::submitChanges(int id) const {
    QJsonArray array;

    for(auto it=lib->begin(); it!=lib->end(); ++it) {
        array.append((*it)->toJson());
    }
    
    QJsonDocument doc(array);
    
    if(!file->open(QIODevice::ReadOnly)) {
        qDebug("Errore di caricamento.");
    }
    
    file->write(doc.toJson());
    file->close();
}

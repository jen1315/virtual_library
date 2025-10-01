#ifndef JSONFILE_H
#define JSONFILE_H

#include <QFile>
#include "./model/AbstractMedia.h"

class JsonFile {

public:
    JsonFile(const QString jsonUrl);
    QMap<int, AbstractMedia*>& getMap() const;
    void submitChanges(int id) const;

private:
    QFile *file;
    QMap<int, AbstractMedia*> *lib;

};

#endif

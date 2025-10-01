#include "Utilities.h"
#include <QJsonDocument>
#include <QLayoutItem>
#include <QWidget>

void Util::remove(QMap<int, AbstractMedia*> lib, QString id) {
    for(auto it = lib.begin(); it!=lib.end(); ++it) {
        if((*it)->getId() == id)
            lib.erase(it);
    }
}

QMap<int, AbstractMedia*>& Util::search(const QMap<int, AbstractMedia*> lib, const QString info) {
    QMap<int, AbstractMedia*> *results = new QMap<int, AbstractMedia*>();
    for(auto it = lib.begin(); it!=lib.end(); ++it) {
        if(((*it)->getTitle()).contains(info) || ((*it)->getDescr()).contains(info))
            results->insert((*it)->getId(), *it);
    }
    return *results;
}

void Util::clearLayout(QLayout *layout) {
    if(!layout)
        return ;

    QLayout *subLayout;
    QWidget *widget = new QWidget();
    while(QLayoutItem *item = layout->takeAt(0)) {
        if(widget = item->widget())
            delete widget;
        else if(subLayout = item->layout())
            clearLayout(subLayout);
        delete item;
    }
}


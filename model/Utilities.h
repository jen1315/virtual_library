#ifndef UTILITIES_H
#define UTILITIES_H

#include <QMap>
#include <QString>
#include <QLayout>
#include "AbstractMedia.h"

namespace Util {
    
    void remove(QMap<int, AbstractMedia*> lib, QString id);
    QMap<int, AbstractMedia*>& search(const QMap<int, AbstractMedia*> lib, const QString info);
    
    void clearLayout(QLayout *layout);

};

#endif

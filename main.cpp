#include <QApplication>
#include <QDebug>
#include "JsonFile.h"
#include "./gui/ViewManager.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    QString json = "media.json";
    JsonFile *jf = new JsonFile(json);
    QMap<int, AbstractMedia*> lib = jf->getMap();

    ViewManager view;
    view.setMedia(lib);
    view.show();

    return app.exec();
}

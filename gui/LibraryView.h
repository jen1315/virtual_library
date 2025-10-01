#ifndef LIBRARY_VIEW_H
#define LIBRARY_VIEW_H

#include <QWidget>
#include <QMap>
#include <QListWidget>
#include <QPushButton>
#include "../model/AbstractMedia.h"


class LibraryView : public QWidget {
    Q_OBJECT

public:
    explicit LibraryView(QWidget *parent=nullptr);
    void displayMedia(QMap<int, AbstractMedia*>& lib);
    AbstractMedia& getMedia(int id);
    QMap<int, AbstractMedia*>& getLibrary() const;
    void setMedia(AbstractMedia& media);
    void addMedia(AbstractMedia& media);
    void clear();

private:
    QMap<int, AbstractMedia*> *library;
    QListWidget *listWidget;
    QPushButton *addButton;

private slots:
    void removeMedia();

signals:
    void mediaSelected(QListWidgetItem* item);
    void addClicked();

};

#endif

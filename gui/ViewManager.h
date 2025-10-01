#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QLineEdit>
#include "LibraryView.h"
#include "MediaView.h"
#include "EditView.h"
#include "AddView.h"

class ViewManager : public QMainWindow {
    Q_OBJECT

public:
    explicit ViewManager(QWidget *parent=nullptr);
    void setMedia(QMap<int, AbstractMedia*>& lib);
    
private:
    QStackedWidget *stackWidget;
    QPushButton *homeButton;
    QLineEdit *searchBar;
    QPushButton *searchButton;

    LibraryView *libraryView;
    MediaView *mediaView;
    LibraryView *searchView;
    EditView *editView;
    AddView *addView;

private slots:
    void viewMedia(QListWidgetItem* item);
    void viewSearch();
    void viewEdit();
    void viewAdd();
    void submitMedia(AbstractMedia* media);
    void addMedia(AbstractMedia* media);
    void switchHome();
};

#endif

#include "LibraryView.h"

#include <QHBoxLayout>
#include <QLabel>

LibraryView::LibraryView(QWidget *parent) : QWidget(parent) {
    listWidget = new QListWidget(this);
    addButton = new QPushButton("Add", this);

    listWidget->setResizeMode(QListView::Adjust);
    listWidget->setSpacing(10);

    QWidget *buttonWidget = new QWidget(this);
    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addWidget(addButton);
    buttonWidget->setLayout(vlayout);    

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(buttonWidget);
    layout->addWidget(listWidget);

    setLayout(layout);
    connect(listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SIGNAL(mediaSelected(QListWidgetItem*)));
    connect(addButton, &QPushButton::clicked, this, &LibraryView::addClicked);
}

void LibraryView::displayMedia(QMap<int, AbstractMedia*>& l) {
    library = new QMap<int, AbstractMedia*>(l);
    clear();
    for(auto it=l.begin(); it!=l.end(); ++it) {
        QListWidgetItem *item = new QListWidgetItem();
        QVariant media((*it)->getId());
        item->setData(Qt::UserRole, media);

        QWidget *widget = new QWidget(this);
        QLabel *titleLabel = new QLabel((*it)->getTitle(), widget);
        QLabel *yearLabel = new QLabel(QString::number((*it)->getYear()), widget);
        QLabel *typeLabel = new QLabel();
       
        QHBoxLayout *wlayout = new QHBoxLayout();
        wlayout->addWidget(titleLabel);
        wlayout->addWidget(yearLabel);
        wlayout->addStretch();
        wlayout->setSizeConstraint(QLayout::SetFixedSize);
        widget->setLayout(wlayout);
        item->setSizeHint(widget->sizeHint());       
    
        listWidget->addItem(item);
        listWidget->setItemWidget(item, widget);
    }
}

AbstractMedia& LibraryView::getMedia(int id) {
    return *((*library)[id]);
}

void LibraryView::setMedia(AbstractMedia& media) {
    int id = media.getId();
    (*library)[id] = &media;
    displayMedia(*library);
}

QMap<int, AbstractMedia*>& LibraryView::getLibrary() const {
    return *library;
}

void LibraryView::clear() {
    listWidget->clear();
}

void LibraryView::addMedia(AbstractMedia& media) {
    int id = library->size();
    media.setId(id);
    (*library)[id] = &media;
    displayMedia(*library);
}

void LibraryView::removeMedia() {
}

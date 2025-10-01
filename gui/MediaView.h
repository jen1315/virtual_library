#ifndef MEDIAVIEW_H
#define MEDIAVIEW_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "../model/AbstractMedia.h"
#include "MediaWidget.h"

class MediaView : public QWidget {
    Q_OBJECT

public:
    explicit MediaView(QWidget *parent = nullptr);
    void displayMedia(AbstractMedia& m);
    AbstractMedia& getMedia() const;
    void clearLayout(QLayout* layout);

private:
    AbstractMedia *media;
    QVBoxLayout *layout;
    QPushButton *editButton;
    QLabel *titleLabel;
    QLabel *yearLabel;
    QLabel *descrLabel;
    QLabel *imageLabel;
    QVBoxLayout *visitLayout;

signals:
    void toEdit();
    
};

#endif

#ifndef EDITVIEW_H
#define EDITVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QTabWidget>
#include "./model/AbstractMedia.h"
#include "MediaWidget.h"

class EditView : public QWidget {
    Q_OBJECT

public:
    explicit EditView(QWidget *parent=nullptr);
    void setMedia(AbstractMedia& media);
    void setAdd();
    
private:
    AbstractMedia *media;
    MediaWidget *visitor;
    QVBoxLayout *layout;
    QLineEdit *titleEdit;
    QLineEdit *yearEdit;
    QLineEdit *imgEdit;
    QTextEdit *descrEdit;
    QPushButton *submitButton;
    QVBoxLayout *detailLayout;

private slots:
    void toSubmit();

signals:
    void submitted(AbstractMedia*);
};

#endif

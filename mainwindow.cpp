#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setup();
}

void
MainWindow::setup()
{
    QPushButton *load = this->ui->load;
    load->setText("Load");
    connect(this->ui->load, &QPushButton::released,
            this, &MainWindow::released);
}

void
MainWindow::released()
{
    //setup form:
    QFormLayout *form = this->ui->formLayout;
    QLineEdit *input = nullptr;

    input = new QLineEdit(this);
    form->addRow("Nom", input);

    input = new QLineEdit(this);
    form->addRow("Team", input);

    input = new QLineEdit(this);
    form->addRow("Field", input);

    //from now simulate that we only have a reference to form;
    input = nullptr;
    QLayoutItem *item_label = nullptr;
    QLayoutItem *item_field = nullptr;

    qDebug() << "form rows: " << form->rowCount();
    for (int i = 0; i < form->rowCount(); ++i) {
        qDebug() << "check item " << i;
        item_label = form->itemAt(i, QFormLayout::LabelRole);
        item_field = form->itemAt(i, QFormLayout::FieldRole);

        QLabel *label = dynamic_cast<QLabel *>(item_label->widget());
        QLineEdit *edit = dynamic_cast<QLineEdit *>(item_field->widget());

        qDebug() << "check label to set according infomrations";
        qDebug() << "found " << label->text();
        if (label->text().compare("Nom") == 0) {
            edit->setText("Doe");
        } else if (label->text().compare("Team") == 0) {
            edit->setText("TITI");
        } else if (label->text().compare("Field") == 0) {
            edit->setText("Beginer");
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

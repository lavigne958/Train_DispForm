#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QPair>

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
    QPushButton *load = this->ui->loadBtn;
    load->setText("Load");

    form_meta.append(QPair<QString,QString>("Nom", "Doe"));
    form_meta.append(QPair<QString, QString>("Team", "Venom"));
    form_meta.append(QPair<QString, QString>("Field", "-100Kg"));
    connect(load, &QPushButton::released,
            this, &MainWindow::released);
}

void
MainWindow::released()
{
    //setup form:
    QFormLayout *form = this->ui->formLayout;
    QLineEdit *input = nullptr;

    input = new QLineEdit(this);
    QString objName;
    for (auto& form_info: this->form_meta) {
        objName = form_info.first + "Edit";
        input = new QLineEdit(this);
        input->setObjectName(objName);
        form->addRow(form_info.first, input);
    }

    //from now simulate that we only have a reference to form;
    input = nullptr;

    for (auto& form_info: this->form_meta) {
        input = MainWindow::findChild<QLineEdit *>(form_info.first + "Edit");
        input->setText(form_info.second);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

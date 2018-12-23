#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
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

    form_meta.append(QPair<QString,QString>("edit:Nom", "Doe"));
    form_meta.append(QPair<QString, QString>("edit:Team", "Venom"));
    form_meta.append(QPair<QString, QString>("edit:Field", "-100Kg"));
    form_meta.append(QPair<QString, QString>("check:Present", "true"));
    connect(load, &QPushButton::released,
            this, &MainWindow::released);
}

void
MainWindow::released()
{
    //setup form:
    QFormLayout *form = this->ui->formLayout;
    QWidget *input = nullptr;

    input = new QLineEdit(this);
    QStringList objNameType;
    for (auto& form_info: this->form_meta) {
        objNameType = form_info.first.split(":");
        if (objNameType[0].compare("edit") == 0) {
            input = new QLineEdit(this);
        } else if (objNameType[0].compare("check") == 0) {
            input = new QCheckBox(this);
        } else {
            qDebug() << "found an object of incomplete type";
        }
        input->setObjectName(objNameType[1]+objNameType[0]);
        form->addRow(objNameType[1], input);
    }

    //from now simulate that we only have a reference to form;
    input = nullptr;

    for (auto& form_info: this->form_meta) {
        objNameType = form_info.first.split(":");

        if (objNameType[0].compare("edit") == 0) {
            QLineEdit *editInput = MainWindow::findChild<QLineEdit *>(objNameType[1]+objNameType[0]);
            editInput->setText(form_info.second);
        } else if (objNameType[0].compare("check") == 0) {
            QCheckBox *checkInput = MainWindow::findChild<QCheckBox *>(objNameType[1]+objNameType[0]);
            checkInput->setCheckState((form_info.second.compare("true") == 0)? Qt::Checked : Qt::Unchecked);
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

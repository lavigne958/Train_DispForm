#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPair>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<QPair<QString, QString>> form_meta;

private:
    Ui::MainWindow *ui;

    void setup();

private slots:
    void released();
};

#endif // MAINWINDOW_H

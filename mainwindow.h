#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "xmlrpc/cliente.h"
using namespace XmlRpc;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_on_off_cliente_clicked();
    void on_on_off_motor_clicked();
    void on_on_off_bt_clicked();
    void on_btn_avanzar_clicked();
    void on_btn_comando_clicked();

private:
    Ui::MainWindow *ui;
    cliente_xmlrpc cliente;
    bool estado_sv = false;
};
#endif // MAINWINDOW_H

#include <mainwindow.h>
#include <ui_mainwindow.h>
#include "xmlrpc/cliente.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_on_off_cliente_clicked()
{
    if (estado_sv != true){

        try{
            char* ip= "127.0.0.1";
            int puerto = 8891;
            cliente_xmlrpc cliete_xmlrpc(ip, puerto);
              //XmlRpc::setVerbosity(5);
              ui->r_log->addItem("Se logró conectar con el servidor");


        }catch(XmlRpc::XmlRpcException e){
            ui->r_log->addItem("No se logró conectar con el servidor");
            cout << "Error numero " << e.getCode() << ", " << e.getMessage() << endl;
        }
    } else {
        try{
            XmlRpc::XmlRpcClient cliete_xmlrpc.close();
            catch(XmlRpc::XmlRpcException e){
                        ui->r_log->addItem("No se logró conectar con el servidor");
                        cout << "Error numero " << e.getCode() << ", " << e.getMessage() << endl;
                    }
        }
    }



    /*
    short hora, min, seg;
    QString tiempoSeg=ui->dato->text();
    long int tiempo=tiempoSeg.toInt();
    seg = tiempo % 60;
    min = (tiempo / 60) % 60;
    hora = (tiempo / 60 / 60);
    ui->resultado->setText(QString::number(hora) + " horas, " + QString::number(min) + " minutos, " + QString::number(seg) + " segundos");
    */
}

void MainWindow::on_on_off_motor_clicked(){
    ui->r_log->addItem("Se presionó boton de motores");
    ui->r_log->addItem("#############################################################");
    ui->r_log->addItem(" ");
    ui->r_log->scrollToBottom();
}
void MainWindow::on_on_off_bt_clicked(){
    ui->r_log->addItem("Se presionó boton de bluetooth");
    ui->r_log->addItem("#############################################################");
    ui->r_log->addItem(" ");
    ui->r_log->scrollToBottom();
}
void MainWindow::on_btn_avanzar_clicked(){
    ui->r_log->addItem("Se presionó boton para avanzar");
    ui->r_log->addItem("#############################################################");
    ui->r_log->addItem(" ");
    ui->r_log->scrollToBottom();
}

void MainWindow::on_btn_comando_clicked(){
    QString text_cl=ui->comando_txt->text();
    ui->r_log->addItem("Se envió al servidor: " + text_cl);
    cliente.ejecutar('escribir', text_cl,);
    ui->r_log->addItem("#############################################################");
    ui->r_log->addItem(" ");
    ui->r_log->scrollToBottom();
}

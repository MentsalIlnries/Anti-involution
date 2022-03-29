#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("124.221.127.132");
        db.setPort(3306);
        db.setDatabaseName("todo");
        db.setUserName("todoManager");
        db.setPassword("anti-involution");
        bool ok = db.open();
        if (ok){
            QMessageBox::information(this, "infor", "success");
        }
        else {
            QMessageBox::information(this, "infor", "open failed");
            qDebug()<<"error open database because"<<db.lastError().text();
        }
//        db.setHostName("127.0.0.1");
//        db.setPort(3306);
//        db.setDatabaseName("Local");
//        db.setUserName("root");
//        db.setPassword("asdfghjkl");
//        bool ok = db.open();
//        if (ok){
//            QMessageBox::information(this, "infor", "success");
//        }
//        else {
//            QMessageBox::information(this, "infor", "open failed");
//            qDebug()<<"error open database because"<<db.lastError().text();
//        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

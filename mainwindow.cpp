#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

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

void MainWindow::on_BtnRed_clicked()
{
    this->ui->render_area->setBackgroundColor({225 , 0 , 0});
    this->ui->render_area->repaint();
}

void MainWindow::on_BtnBlue_clicked()
{
    this->ui->render_area->setBackgroundColor({0 , 0 , 225});
    this->ui->render_area->repaint();
}

void MainWindow::on_BtnGreen_clicked()
{
    this->ui->render_area->setBackgroundColor({0 , 225 , 0});
    this->ui->render_area->repaint();
}

void MainWindow::on_BtnYellow_clicked()
{
    this->ui->render_area->setBackgroundColor({255 , 255 , 0});
    this->ui->render_area->change_shape();
    this->ui->render_area->repaint();
}

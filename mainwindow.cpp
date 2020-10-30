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
    this->ui->render_area->set_shape(RenderArea::shape1);
    this->ui->render_area->repaint();
}

void MainWindow::on_BtnBlue_clicked()
{

    this->ui->render_area->set_shape(RenderArea::shape2);
    this->ui->render_area->repaint();
}

void MainWindow::on_BtnGreen_clicked()
{

    this->ui->render_area->set_shape(RenderArea::shape3);
    this->ui->render_area->repaint();
}

void MainWindow::on_BtnYellow_clicked()
{

    this->ui->render_area->set_shape(RenderArea::shape4);
    this->ui->render_area->repaint();
}

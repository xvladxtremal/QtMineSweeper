#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newGame(int height = 5, int width = 5){
    this->table = new MineTable(height,width,this);
    this->setCentralWidget(this->table);
}

void MainWindow::on_new5x5_triggered()
{
    this->newGame(5,5);
}

void MainWindow::on_new7x7_triggered()
{
    this->newGame(7,7);
}

void MainWindow::on_new9x9_triggered()
{
    this->newGame(9,9);
}

void MainWindow::on_new14x14_triggered()
{
    this->newGame(14,14);
}

void MainWindow::on_new20x20_triggered()
{
    this->newGame(20,20);
}

void MainWindow::on_new40x40_triggered()
{
    this->newGame(40,40);
}

void MainWindow::on_new50x50_triggered()
{
    this->newGame(50,50);
}

void MainWindow::on_new80x80_triggered()
{
    this->newGame(80,80);
}

void MainWindow::on_new100x100_triggered()
{
    this->newGame(80,80);
}


void MainWindow::on_aboutQt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_about_triggered()
{
    QMessageBox::about(this,"О программе \"Сапёр\"","Created by Vladyslav Volynets(xvladxtreme@gmail.com)");
}

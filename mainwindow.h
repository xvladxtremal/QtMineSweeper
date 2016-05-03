#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define HEIGHT 10
#define WIDTH 10

#include <QMainWindow>
#include <QtGlobal>
#include <QVector>
#include "minecell.h"
#include "minetable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    MineTable *table;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void newGame(int height, int width);
private slots:
    void on_new5x5_triggered();
    void on_new7x7_triggered();
    void on_new9x9_triggered();
    void on_new14x14_triggered();
    void on_new20x20_triggered();
    void on_new40x40_triggered();
    void on_new50x50_triggered();
    void on_new80x80_triggered();
    void on_new100x100_triggered();
    void on_aboutQt_triggered();
    void on_about_triggered();
};

#endif // MAINWINDOW_H

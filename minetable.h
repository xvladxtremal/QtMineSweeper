#ifndef MINETABLE_H
#define MINETABLE_H

#include <QObject>
#include <QMessageBox>
#include <QVector>
#include <QBitArray>
#include <QtGlobal>
#include <QDebug>
#include <QtAlgorithms>
#include <QGridLayout>
#include <QTime>
#include "minecell.h"

class MineTable : public QWidget
{
    Q_OBJECT

protected:
    int m_height;
    int m_width;
    int m_numBombs;
    bool m_isActiveGame;
private:
    QVector<QVector<MineCell*>> *table;
    QVector<QBitArray> *tableBool;

    QVector<int> generateMines(int height, int width);
    int checkNextMines(int i, int j);
    void formBoolTable(QVector<int> randCells);
    void createTableFromBool();
    bool ifValidCoords(int x, int y);
public:
    explicit MineTable(int m_height = 9, int width = 9, QWidget *parent = 0);
    QGridLayout *tableLayout;

signals:
    void endGame();
public slots:
    void on_cellClickedLeft();
    void on_cellClickedRight();
    void on_endGame();
};

#endif // MINETABLE_H

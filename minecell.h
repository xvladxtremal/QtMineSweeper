#ifndef MINECELL_H
#define MINECELL_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>

class MineCell : public QPushButton
{
    Q_OBJECT

private:
    bool isClicked;
protected:
    bool m_isMine;
    bool m_isOpen;
    bool m_isFlag;
    int m_nextMine;
    bool m_isActiveGame;

public:
    explicit MineCell(bool m_isMine,
                      int m_nextMine = 0,
                      int x = 0,
                      int y = 0,
                      QWidget *parent = 0);
    int m_x;
    int m_y;

    bool isMine();
    bool isOpen();
    bool isFlag();
    int  getNextMines();
signals:
    leftClicked();
    rightClicked();

    dieGame();
    winGame();

public slots:
    void openCell();
    void toogleFlag();
    void clicked();
    void on_endGame();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *e);

};

#endif // MINECELL_H

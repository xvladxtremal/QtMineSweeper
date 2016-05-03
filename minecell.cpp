#include "minecell.h"

MineCell::MineCell(bool hasMine, int nextMine, int x, int y, QWidget *parent) :
    QPushButton(parent),
    m_nextMine(nextMine),
    m_isMine(hasMine),
    m_x(x),
    m_y(y),
    m_isFlag(false),
    m_isOpen(false),
    m_isActiveGame(true),
    isClicked(false)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMinimumSize(15, 15);

    connect(this, SIGNAL(rightClicked()),  SLOT(toogleFlag()    ));
    connect(this, SIGNAL(leftClicked() ) , SLOT(openCell()      ));
    this->repaint();
}

void MineCell::openCell(){
    if(this->m_isActiveGame){
        if(!this->m_isOpen){
            this->m_isOpen = true;
            if(this->m_isActiveGame){
                if(this->m_isMine && this->isClicked){
                    emit dieGame();
                    this->m_isActiveGame = false;
                }
            }
        }
    }
    this->isClicked = false;
    repaint();
}

void MineCell::mousePressEvent(QMouseEvent *e)
{
    this->isClicked = true;

    if(this->m_isActiveGame){
        if(e->button()==Qt::RightButton){
            emit rightClicked();
        }else{
            emit leftClicked();
        }
    }else{
        return;
    }
}

void MineCell::clicked(){
    return;
}

void MineCell::toogleFlag(){
    this->m_isFlag = this->m_isFlag ? false : true;
}

bool MineCell::isMine(){
    return this->m_isMine;
}

bool MineCell::isOpen(){
    return this->m_isOpen;
}

bool MineCell::isFlag(){
    return this->m_isFlag;
}

void MineCell::on_endGame(){
    this->m_isActiveGame = false;
}

int  MineCell::getNextMines(){
    return m_nextMine;
}

/*virtual*/ void MineCell::paintEvent(QPaintEvent *event) {

  QPushButton::paintEvent(event);
  QPainter p(this);
  QPixmap pixmap;
  this->isClicked = true;
  if (this->isOpen()) {
    if (this->isMine()) {
        pixmap.load(":/mine.png");
        p.drawPixmap(2, 2, width() - 4, height() - 4, pixmap);
    }else if(this->getNextMines() == 0){
        setFlat(true);
    }else{
        setText(QString::number(this->getNextMines()));
        setFlat(true);
    }
  }
  if (this->isFlag()) {
    p.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    p.drawEllipse(2, 2, width() - 4, height() - 4);
  }
}

#include "minetable.h"

MineTable::MineTable(int height, int width, QWidget *parent) : QWidget(parent),
   m_height(height),
   m_width(width),
   m_isActiveGame(true)
{
    this->tableLayout = new QGridLayout(this);
    this->tableLayout->setHorizontalSpacing(1);
    this->tableLayout->setVerticalSpacing(1);

    QVector<int> randCells = this->generateMines(height,width);
    qSort(randCells.begin(),randCells.end());
    this->m_numBombs = randCells.length();

    this->tableBool = new QVector<QBitArray>;
    this->table = new QVector<QVector<MineCell*>> ;

    this->formBoolTable(randCells);
    this->createTableFromBool();

    this->setLayout(tableLayout);


}

void MineTable::createTableFromBool(){
    for(int i = 0; i<this->m_height ; ++i){
        QVector<MineCell*> tempLine;
        for(int j = 0; j<this->m_width ; ++j){
            MineCell* tempCell = new MineCell(
                                    this->tableBool->value(i).at(j),
                                    checkNextMines(i,j),
                                    j,
                                    i,
                                    this
                                    );
            this->tableLayout->addWidget(tempCell, i, j, 1, 1);
            connect(tempCell, SIGNAL(leftClicked()),    this,       SLOT(on_cellClickedLeft()));
            connect(tempCell, SIGNAL(rightClicked()),   this,       SLOT(on_cellClickedRight()));
            //connect(tempCell, SIGNAL(dieGame()),        this,       SLOT(on_endGame()));
            //connect(this    , SIGNAL(endGame()),        tempCell,   SLOT(on_endGame()));
            tempLine.append(tempCell);
        }
        this->table->append(tempLine);
    }
}

void MineTable::formBoolTable(QVector<int> randCells){
    for(int i = 0; i<this->m_height; i++){
        QBitArray tempBit = QBitArray(this->m_width);
        for(int j = 0; j<this->m_width; j++){
            if(randCells.contains((i+1)*(j+1))){
                tempBit.setBit(j,true);
            }
        }
        this->tableBool->append(tempBit);
    }
}

int MineTable::checkNextMines(int i, int j){

    int ii = i, jj = j;
    int nextMines = 0;

    if(ii - 1 >= 0 ){
        if(jj - 1 >= 0){
            nextMines += (int)this->tableBool->value(ii - 1).at(jj - 1);
        }
        nextMines += (int)this->tableBool->value(ii - 1).at(jj);
        if(jj + 1 < this->m_width){
            nextMines += (int)this->tableBool->value(ii - 1).at(jj + 1);
        }
    }
    if(jj - 1 >= 0){
        nextMines += (int)this->tableBool->value(ii).at(jj - 1);
    }
    if(jj + 1 < this->m_width){
        nextMines += (int)this->tableBool->value(ii).at(jj + 1);
    }
    if(ii + 1 < this->m_height ){
        if(jj - 1 >= 0){
            nextMines += (int)this->tableBool->value(ii + 1).at(jj - 1);
        }
        nextMines += (int)this->tableBool->value(ii + 1).at(jj);
        if(jj + 1 < this->m_width){
            nextMines += (int)this->tableBool->value(ii + 1).at(jj + 1);
        }
    }

    return nextMines;
}

QVector<int> MineTable::generateMines(int height, int width){
    QVector<int> randDigits;
    int tempDigit;

    qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));

    double tableLenght = height*width;
    int minesNum = (int)(tableLenght/100*15);

    for(int i = 0; randDigits.length()<minesNum; i++){
        do{
            tempDigit = qrand()%(int)tableLenght;
        }while(randDigits.contains(tempDigit));

        randDigits.append(tempDigit);
    }
    return randDigits;
}

bool MineTable::ifValidCoords(int x, int y){
    if(     x >= 0              &&
            x < this->m_width   &&
            y >= 0              &&
            y < this->m_height
    ){
        return true;
    }else{
        return false;
    }
}

void MineTable::on_cellClickedLeft(){
    int ii = 0,jj=0;
    if(this->ifValidCoords(ii-1,jj-1) && !table->value(ii-1).value(jj-1)->isMine()){
        table->value(ii-1).value(jj-1)->openCell();
    }

    if(this->ifValidCoords(ii-1,jj) && !table->value(ii-1).value(jj)->isMine()){
        table->value(ii-1).value(jj)->openCell();
    }

    if(this->ifValidCoords(ii-1,jj+1) && !table->value(ii-1).value(jj+1)->isMine()){
        table->value(ii-1).value(jj+1)->openCell();
    }

    if(this->ifValidCoords(ii,jj-1) && !table->value(ii).value(jj-1)->isMine()){
        table->value(ii).value(jj-1)->openCell();
    }

    if(this->ifValidCoords(ii,jj+1) && !table->value(ii).value(jj+1)->isMine()){
        table->value(ii).value(jj+1)->openCell();
    }

    if(this->ifValidCoords(ii+1,jj+1) && !table->value(ii+1).value(jj+1)->isMine()){
        table->value(ii+1).value(jj+1)->openCell();
    }

    if(this->ifValidCoords(ii+1,jj) && !table->value(ii+1).value(jj)->isMine()){
        table->value(ii+1).value(jj)->openCell();
    }

    if(this->ifValidCoords(ii+1,jj-1) && !table->value(ii+1).value(jj-1)->isMine()){
        table->value(ii+1).value(jj-1)->openCell();
    }
}

void MineTable::on_cellClickedRight(){

}

void MineTable::on_endGame(){
    emit endGame();
    QMessageBox *dialogEnd = new QMessageBox(QMessageBox::NoIcon, "Конец игры", "Вы проиграли", QMessageBox::Ok	);
    dialogEnd->show();
    this->m_isActiveGame = false;
}

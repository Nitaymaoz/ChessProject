#include "King.h"
#include <cstdlib>
using namespace std;


King::King(Player *pl, char sign, int row, int col, Board *brd):Piece(pl,sign,row,col,brd) {}

bool King::isChess() {
    Piece* lastMovedPiece = this->_brd->getMovedPiece();
    if (lastMovedPiece->isLegalMove(this->_row,this->_col)) return true;
    return false;
}

bool King::isLegalMove(int row , int col) const {
    if (abs(this->_row-row)<=1 && abs(this->_col-col)<=1)
        return true;
    return false;
}
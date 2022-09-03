#include "Queen.h"
#include <cstdlib>
using namespace std;


Queen::Queen(Player *pl, char sign, int row, int col, Board *brd):Piece(pl,sign,row,col,brd) {}

bool Queen::isLegalMove(int row, int col) const {
    if ( isWayFree(row,col)){
        if (abs(this->_row - row) == abs(this->_col - col)) return true;
        else if ((this->_col == col || this->_row == row)) return true;
        return false;
    }

}
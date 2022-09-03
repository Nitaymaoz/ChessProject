#include "Knight.h"
#include <cstdlib>
using namespace std;

Knight::Knight(Player * pl,char sign, int row, int col, Board * brd): Piece(pl,sign,row,col,brd) {}

bool Knight::isLegalMove(int row, int col) const {
    if ((abs(this->_row-row)==2 && abs(this->_col-col)==1) || (abs(this->_row-row)==1 && abs(this->_col-col)==2)) ///has to move 2 squares towards one location and one toward the other location
    return true;

    return false;
}
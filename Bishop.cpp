#include "Bishop.h"
#include <cstdlib>

using namespace std;

Bishop::Bishop(Player *pl, char sign, int row, int col, Board *brd) : Piece(pl, sign, row, col, brd) {}

bool Bishop::isLegalMove(int row, int col) const {
    if (isWayFree(row, col)) {
        if (abs(this->_row - row) == abs(this->_col - col)) return true;
        return false;
    }
}
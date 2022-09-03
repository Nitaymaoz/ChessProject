#include "Rook.h"

using namespace std;

Rook::Rook(Player *pl, char sign, int row, int col, Board *brd) : Piece(pl, 'r', row, col, brd) {}

bool Rook::isLegalMove(int row, int col) const {
    if (this->isWayFree(col, row)) {
        if (this->_col == col || this->_row == row)
            return true;
    }
    return false;
}




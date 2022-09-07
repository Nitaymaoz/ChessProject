#include "King.h"
#include <cstdlib>
using namespace std;


King::King(Player *pl, char sign, int row, int col, Board *brd):Piece(pl,sign,row,col,brd) {}

bool King::isChess() {
    Piece** matBoard = _brd->getBoard();
    Piece* currPiece = NULL;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            currPiece = *(matBoard + i * BOARD_SIZE + j);
            if ((currPiece->getSign() == '#') || (currPiece->getPlayer()) == _player)
                continue;
            if (currPiece->isLegalMove(this->_row, this->_col))
                return true;
        }
    }
    return false;
}

bool King::isLegalMove(int row , int col) const {
    if (abs(this->_row-row)<=1 && abs(this->_col-col)<=1)
        return true;
    return false;
}
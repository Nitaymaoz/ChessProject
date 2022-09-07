#include "Pawn.h"
using namespace std;
#include <cstdlib>


bool Pawn::isLegalMove(int row, int col) const {
    int numofsteps = 0;
    Piece* destpiece = *(this->_brd->getBoard() + row * BOARD_SIZE + col);
    _player->isGoingUp() ? numofsteps =row -this->_row : numofsteps= this->_row - row;
    if (numofsteps <= 0 || numofsteps > 2 || (numofsteps==2 && !firststep))            /// not a legal move - can't stay in place or go back & not allowed to take 2 steps
        return false;
    else if (_col==col && numofsteps<=2) {                                              /// move forward only ( 1 or 2 steps)
        return isWayFree(row, col) && destpiece->getSign() == '#';
    }
    return ((abs(col-this->_col)==1) && numofsteps==1 && destpiece->getSign()!='#' && destpiece->getPlayer()!=_player); ///eat another player piece diagonal


}
Pawn::Pawn(Player *pl,char sign, int row, int col, Board *brd): Piece(pl,sign,row,col,brd) , firststep(true) {}

void Pawn::setFirstStep() {
    this->firststep= false;
}

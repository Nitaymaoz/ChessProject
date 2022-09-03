#include "King.h"
using namespace std;


King::King(Player *pl, char sign, int row, int col, Board *brd):Piece(pl,sign,row,col,brd) {}

bool King::isChess() {return true;}

bool King::isLegalMove(int, int) const {return true;}
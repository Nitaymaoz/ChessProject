#include "Bishop.h"

using namespace std;

Bishop::Bishop(Player *pl, char sign, int row, int col, Board *brd) :Piece(pl,sign,row,col,brd){}

bool Bishop::isLegalMove(int, int) const {return true;}
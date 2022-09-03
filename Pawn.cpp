#include "Pawn.h"
using namespace std;


bool Pawn::isLegalMove(int, int) const {return true;}
Pawn::Pawn(Player *pl,char sign, int row, int col, Board *brd): Piece(pl,sign,row,col,brd) {}
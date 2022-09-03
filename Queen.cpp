#include "Queen.h"
using namespace std;


Queen::Queen(Player *pl, char sign, int row, int col, Board *brd):Piece(pl,sign,row,col,brd) {}

bool Queen::isLegalMove(int, int) const {return true;}
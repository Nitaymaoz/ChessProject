#include "Knight.h"
using namespace std;

Knight::Knight(Player * pl,char sign, int row, int col, Board * brd): Piece(pl,sign,row,col,brd) {}

bool Knight::isLegalMove(int, int) const {return true;}
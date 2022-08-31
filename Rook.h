#pragma once

#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(Player*,char sign, int row, int col, Board*);
	virtual bool isLegalMove(int, int) const;

private:

};
#pragma once

#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Player*, char sign,int row, int col, Board*);

	virtual bool isLegalMove(int, int) const;
private:
};
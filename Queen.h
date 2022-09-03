

#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(Player*, char sign,int row, int col, Board*);
	virtual bool isLegalMove(int, int) const;

private:

};
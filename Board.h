#pragma once

#include "Piece.h"
#include "Player.h"


#define BOARD_SIZE 8

using namespace std;

class Player;
class Piece;

class Board
{
public:
	Board(Player*, Player*); /// What will this do
	~Board();
	void print() const;
	void getString(char res[]) const; ///fix
	bool isPieceOfPlayer(int row, int col, Player* pl) const;
	bool tryMove(int srcRow, int srcCol, int dstRow, int dstCol) const;
	Piece** getBoard() const;
	void Move(int srcRow, int srcCol, int dstRow, int dstCol) ; ///check if works
	void undoLastMove();

private:
	Piece* _brd[BOARD_SIZE][BOARD_SIZE];

	int _lastSrcRow;
	int _lastSrcCol;
	int _lastDstRow;
	int _lastDstCol;
	Piece* _lastPiece;
    int moveCount;
};
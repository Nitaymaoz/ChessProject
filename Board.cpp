#include "Piece.h"
#include <string>
#include <iostream>
#include "Pawn.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Player.h"
#include "Queen.h"
#include "Rook.h"
#include "Board.h"
#include "NullPiece.h"

using namespace std;

Board::Board(Player * player1, Player * player2){
    _brd[0][0]= new Rook(player1,0,0,*_brd);
}

Board::~Board() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            delete _brd[i][j];
        }
    }
    delete _lastPiece;
}

void Board::print() const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std:: cout << _brd[i][j]->getSign() << ' ';
        }
        std::cout << endl;
    }
}

void Board::getString(char *res) const{
    int size = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            res[size++] = _brd[i][j]->getSign();
        }
    }
    res[size++] = 0; //white player starts
    res[size]= '\0'; // null at the end of the array
}

bool Board::isPieceOfPlayer(int row, int col, Player *pl) const {
    if (pl->isWhite() && _brd[row][col]->getPlayer()->isWhite())
        return true;
    else if (!pl->isWhite() && !_brd[row][col]->getPlayer()->isWhite())
            return true;
    return false;
}

bool Board::tryMove(int srcRow, int srcCol, int dstRow, int dstCol) const {

    return _brd[srcRow][srcCol]->isLegalMove(dstRow,dstCol);


//    if (_brd[srcCol][srcRow]->getSign()=='#')
//        return false;
//    else {
//        if (_brd[dstCol][dstCol]->getSign() == '#')
//            return true;
//        bool iswhite = _brd[srcCol][srcRow]->getPlayer()->isWhite();
//        bool dst = _brd[dstCol][dstCol]->getPlayer()->isWhite();
//        if (iswhite != dst) ///src different from dst hence eat.
//            return true;
//        return false; /// dst has current player piece
//    }
}

Piece **Board::getBoard() const {
    return (Piece **)_brd;
}

void Board::Move(int srcRow, int srcCol, int dstRow, int dstCol) {
    if (_lastPiece != nullptr)
        delete _lastPiece;

    _lastPiece = _brd[dstRow][dstCol];
    _lastSrcRow = srcRow;
    _lastSrcCol = srcCol;
    _lastDstRow = dstRow;
    _lastDstCol = dstCol;
    _brd[srcRow][srcCol]->setPosition(dstRow,dstCol);
    _brd[dstRow][dstCol]=_brd[srcRow][srcCol];
    _brd[srcRow][srcCol] = new NullPiece(srcRow, srcCol); ///check if inner location changed
}

void Board::undoLastMove() {
    if (_lastPiece== nullptr) // Second undo in a row - do nothing
        return;

    delete _brd[_lastSrcRow][_lastSrcCol]; // avoid memory leaks
    _brd[_lastSrcRow][_lastSrcCol] = _brd[_lastDstRow][_lastDstCol]; // move piece back
    _brd[_lastSrcRow][_lastSrcCol]->setPosition(_lastSrcRow,_lastSrcCol); //set inner location
    _brd[_lastDstRow][_lastDstCol]=_lastPiece;  // replace the last piece
    _lastPiece= nullptr;
}
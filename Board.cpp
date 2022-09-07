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

Board::Board(Player * player1, Player * player2):_lastPiece(nullptr), moveCount(1){
    if (!player1->isWhite()){
        ///black player top - player 1
        _brd[0][0]=(Piece*) new Rook(player1,'r',0,0,this);
        _brd[0][7]=(Piece*) new Rook(player1,'r',0,7,this);
        _brd[0][1]=(Piece*) new Knight(player1,'n',0,1,this);
        _brd[0][6]=(Piece*) new Knight(player1,'n',0,6,this);
        _brd[0][2]=(Piece*) new Bishop(player1,'b',0,2,this);
        _brd[0][5]=(Piece*) new Bishop(player1,'b',0,5,this);
        _brd[0][3]=(Piece*) new Queen(player1,'q',0,3,this);
        player1->setKing(new King(player1,'k',0,4,this));
        _brd[0][4]=(Piece*)player1->getKing();


        ///white player at bottom - player 2
        _brd[7][0]= (Piece*)new Rook(player2,'R',7,0,this);
        _brd[7][7]=(Piece*) new Rook(player2,'R',7,7,this);
        _brd[7][1]=(Piece*) new Knight(player2,'N',7,1,this);
        _brd[7][6]=(Piece*) new Knight(player2,'N',7,6,this);
        _brd[7][2]=(Piece*) new Bishop(player2,'B',7,2,this);
        _brd[7][5]=(Piece*) new Bishop(player2,'B',7,5,this);
        _brd[7][3]=(Piece*) new Queen(player2,'Q',7,3,this);
        player2->setKing(new King(player2,'k',7,4,this));
        _brd[7][4]=(Piece*) player2->getKing();


        ///pawns
        for (int i = 0; i < 7; ++i) {
            _brd[1][i]=(Piece*) new Pawn(player1,'p',1,i,this);
        }
        for (int i = 0; i < 7; ++i) {
            _brd[6][i]=(Piece*) new Pawn(player2,'P',6,i,this);
        }

    }
    else{
        ///black player top - player 2
        _brd[0][0]=(Piece*) new Rook(player2,'r',0,0,this);
        _brd[0][7]=(Piece*) new Rook(player2,'r',0,7,this);
        _brd[0][1]=(Piece*) new Knight(player2,'n',0,1,this);
        _brd[0][6]=(Piece*) new Knight(player2,'n',0,6,this);
        _brd[0][2]=(Piece*) new Bishop(player2,'b',0,2,this);
        _brd[0][5]=(Piece*) new Bishop(player2,'b',0,5,this);
        _brd[0][3]=(Piece*) new Queen(player2,'q',0,3,this);
        player2->setKing(new King(player2,'k',0,4,this));
        _brd[0][4]=(Piece*)player2->getKing();

        ///white player at bottom - player 1
        _brd[7][0]= (Piece*)new Rook(player1,'R',7,0,this);
        _brd[7][7]=(Piece*) new Rook(player1,'R',7,7,this);
        _brd[7][1]=(Piece*) new Knight(player1,'N',7,1,this);
        _brd[7][6]=(Piece*) new Knight(player1,'N',7,6,this);
        _brd[7][2]=(Piece*) new Bishop(player1,'B',7,2,this);
        _brd[7][5]=(Piece*) new Bishop(player1,'B',7,5,this);
        _brd[7][3]=(Piece*) new Queen(player1,'Q',7,3,this);
        player1->setKing(new King(player1,'k',7,4,this));
        _brd[7][4]=(Piece*) player1->getKing();

        ///pawns
        for (int i = 0; i < 8; ++i) {
            _brd[1][i]=(Piece*) new Pawn(player2,'p',1,i,this);
        }
        for (int i = 0; i < 8; ++i) {
            _brd[6][i]=(Piece*) new Pawn(player1,'P',6,i,this);
        }
    }

    ///Empty spaces - add pawns in rows 1 and 7
    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            _brd[i][j]=new NullPiece (i,j);
        }
    }



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
    if (_brd[row][col]->getPlayer()== nullptr)
        return false;
    else if (pl->isWhite() && _brd[row][col]->getPlayer()->isWhite())
        return true;
    else if (!pl->isWhite() && !_brd[row][col]->getPlayer()->isWhite())
            return true;
    return false;
}

bool Board::tryMove(int srcRow, int srcCol, int dstRow, int dstCol) const {

    return _brd[srcRow][srcCol]->isLegalMove(dstRow,dstCol);
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
    _brd[srcRow][srcCol] = new NullPiece(srcRow, srcCol);

    if (_brd[dstRow][dstCol]->getSign()=='P' ||_brd[dstRow][dstCol]->getSign()=='p'){
        Pawn* pawn = dynamic_cast<Pawn*>(_brd[dstRow][dstCol]);
        pawn->setFirstStep();                                                         ///cancel 2 steps after first move
    }
    std::cout<<endl; std::cout<< "move: " << moveCount++ <<endl;  /// count moves - test purposes
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







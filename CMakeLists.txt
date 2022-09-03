cmake_minimum_required(VERSION 3.23)
project(ChessProject)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ChessProject
        Bishop.h
        Board.h
        King.h
        Knight.h
        Manager.cpp
        Manager.h
        NullPiece.cpp
        NullPiece.h
        Pawn.h
        Piece.cpp
        Piece.h
        Pipe.h
        Player.cpp
        Player.h
        Queen.h
        Rook.h
        stdafx.cpp
        stdafx.h
        targetver.h
        Board.cpp Rook.cpp Knight.cpp Bishop.cpp Queen.cpp King.cpp Pawn.cpp
        Source.cpp)


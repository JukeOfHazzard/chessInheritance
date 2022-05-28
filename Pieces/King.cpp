//
//  King.cpp
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#include "King.h"

// Board class prototype/forward declaration in Piece.h
// #include "board.h" in pieces .cpp files
// all of this allows us to include Board obj as
// a parameter without having circular imports
// (so basically it's just convenient black magic)
#include "board.h"

void King::getMoves(vector<Move> & moves, const Board & board) const {
   const Delta d[8] = {
       {-1,  1}, { 0,  1}, { 1,  1},
       {-1,  0},           { 1,  0},
       {-1, -0}, { 0, -1}, {-1, -1}
   };
   moves = getMoveNoSlide(board, d, 8);
   
   if(!isMoved()) {
      Position posSpace(position.getRow(), 5);
      Position posMove(position.getRow(), 6);
      Position posRook(position.getRow(), 7);
     
      if(board[posMove]->getLetter() == ' ' &&
         board[posSpace]->getLetter() == ' ' &&
         tolower(board[posRook]->getLetter()) == 'r' &&
         board[posRook]->isMoved() == false)
      {
         Move move;
         move.setSource(getPosition());
         move.setDestination(posMove);
         move.setWhiteMove(isWhite());
         move.setCastle(true);
         moves.push_back(move);
      }
   }
   
   if(!isMoved()) {
        Position posSpace1(position.getRow(), 3);
        Position posMove(position.getRow(), 2);
        Position posSpace2(position.getRow(), 1);
        Position posRook(position.getRow(), 0);
     
      if(board[posMove]->getLetter() == ' ' &&
         board[posSpace1]->getLetter() == ' ' &&
         board[posSpace2]->getLetter() == ' ' &&
         tolower(board[posRook]->getLetter()) == 'r' &&
         board[posRook]->isMoved() == false)
      {
         Move move;
         move.setSource(getPosition());
         move.setDestination(posMove);
         move.setWhiteMove(isWhite());
         move.setCastle(false);
         moves.push_back(move);
      }
   }
}

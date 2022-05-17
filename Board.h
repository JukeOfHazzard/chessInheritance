//
//  Board.h
//  Lab01
//
//  Created by Elijah Harrison on 5/14/22.
//


#include "Pieces/Piece.h"
#include "Move.h"
#include "uiDraw.h"
#include "Position.h"
#include <iostream>
#include <set>

#ifndef Board_h
#define Board_h

class Board {
private:
   Piece peices[64];
   Move currentMove;
   ogstream gout;
   
   Piece createPeice(char p);
public:
   Board()
   {
      //can make function that will allow the importing of different boards
      char board[64] ={
         'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
         'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
         'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
         'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
      for(int i = 0; i < 64; i++)
      {
         //just to see if it can create a board
         peices[i] = createPeice(board[i]);
      }
   }
   int getCurrentMove();
   bool whiteTurn();
   void display();
   Piece getP();
   void free();
   void reset();
   void move(Move m);
   void swap(Position p1, Position p2)
   {
//      std::swap(peices[p1.getLocation()], peices[p2.getLocation()]);
   }
   void assertBoard();
   
};

#endif /* Board_h */

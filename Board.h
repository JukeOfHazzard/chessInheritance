//
//  Board.h
//  Lab01
//
//  Created by Elijah Harrison on 5/14/22.
//


#include "Pieces/Piece.h"
//#include "Pieces/..."
//#include "Pieces/King.h"
//#include "Pieces/Queen.h"
//#include "Pieces/Rook.h"
//#include "Pieces/Knight.h"
//#include "Pieces/Bishop.h"
//#include "Pieces/Pawn.h"
//#include "Pieces/Space.h"

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
public:
   Board()
   {
   }
   int getCurrentMove();
   bool whiteTurn();
   void display();
   void free();
   void reset();
   void move(Move m);
   void swap(Position p1, Position p2)
   {
//      std::swap(peices[p1.getLocation()], peices[p2.getLocation()]);
   }
   void assertBoard();
   
   bool operator == (Position & p)
   {
      //stubbed
      return true;
   }
   
   Board operator [] (Position & rhs)
   {
      //stubbed
      return *this;
   }
   
};

#endif /* Board_h */

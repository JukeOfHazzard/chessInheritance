//
//  Board.h
//  Lab01
//
//  Created by Elijah Harrison on 5/14/22.
//

#ifndef Board_h
#define Board_h

#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Space.h"

#include "Move.h"
#include "uiDraw.h"
#include "Position.h"
#include <iostream>
#include <set>

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

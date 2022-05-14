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
public:
   Board() {}
   int getCurrentMove();
   bool whiteTurn();
   void display();
   Piece getP();
   void free();
   void reset();
   void move(Move m);
   void swap(Position p1, Position p2);
   void assertBoard();
   
};

#endif /* Board_h */

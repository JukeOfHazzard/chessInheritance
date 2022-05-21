//
//  Board.h
//  Lab01
//
//  Created by Elijah Harrison on 5/14/22.
//

#ifndef Board_h
#define Board_h

#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Space.h"

#include "Move.h"
#include "Position.h"
#include "uiDraw.h"
#include <iostream>
using namespace std;

class Board {
private:
   Piece* pieces[64]; // using pointers because this allows abstraction
   Move currentMove;
//   ogstream gout; // uncomment this after implementing, it's throwing errors rn
public:
   Board() { }
   
   void display();
   void free();
   void reset();
   void move(Move m);
   void swap(Position p1, Position p2) {
//      std::swap(peices[p1.getLocation()], peices[p2.getLocation()]);
   }
   void assertBoard();
   
   // getters
   int getCurrentMove();
   bool whiteTurn();
   
   // operators
   bool operator == (Position & p) const {
      //stubbed
      return true;
   }
   
   char operator [] (Position & rhs) const {
      // used to refer to board as board[position] rather than board.board[position]
      return pieces[rhs.getLocation()]->getLetter();
   }
   
   char operator [] (Position & rhs) {
      return pieces[rhs.getLocation()]->getLetter();
   }
};

#endif /* Board_h */

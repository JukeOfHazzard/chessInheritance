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
#include "Pieces/Piece.h"

#include "Move.h"
#include "Position.h"
#include "uiDraw.h"
#include <iostream>
using namespace std;

class Board {
protected:
   void assertBoard();
   Piece* board[8][8]; // using pointers because this allows abstraction
   int currentMove;
   ogstream * pgout;

public:
//   Board() { }
   Board(ogstream * pgout, bool noreset = false) : currentMove(-1), pgout(pgout)
   {
      if(!noreset)
         reset(false);
   }
   ~Board()
   {
      free();
   }
   //setters
   void free();
   virtual void reset(bool fFree = true);
   void move(const Move & m);
   void swap(const Position & p1, const Position & p2);
   void setCurrentMove(int currentMove) {this->currentMove = currentMove;}
   void operator -= (const Position & rhs);
   void operator -= (const Move & rhs);
   void remove(const Position & pos);
   const Piece* operator = (Piece & pRhs);
   Piece & operator [] (const Position & rhs)
   {
      return *board[rhs.getRow()][rhs.getCol()];
   }
   
   // getters
   int getCurrentMove() const { return currentMove;}
   bool whiteTurn() const {return getCurrentMove() % 2 == 1;}
   void display(const Position & posHover, const Position & posSelect) const;
   const Piece & operator [] (const Position & rhs) const {
      return *board[rhs.getRow()][rhs.getCol()];
   }
   
   
};

#endif /* Board_h */

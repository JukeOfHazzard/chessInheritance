//
//  Piece.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Piece_h
#define Piece_h

#include "Position.h"
#include "Board.h"
#include "uiDraw.h"

class Piece {
protected:
   Position postion;
   bool fWhite;
   int nMoves;
   int lastMove;
public:
   // Piece() {}
   Piece (char row, char col, bool white)
   {
      this->position = Position(row, col)
   }
   Piece(Position & rhs) { assign(rhs); }
   Piece(const Piece & rhs) { assign(rhs); }

   void assign(Position & rhs){}
   void assign(Piece & rhs){}

   bool isWhite() const {return true;} //stubbed
   bool isMove() const {return true;} //stubbed
   int getNMoves() {}
   Position getPosition (return postion) {}
   bool justMoved() {return true; }

   virtual char getLetter() = default;
   virtual void display(ogstream & gout) = default;
   virtual set<Move> getMoves(Board board) = default;
};

#endif /* Piece_h */

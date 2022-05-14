//
//  Piece.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Piece_h
#define Piece_h

#include "Board.h"
#include "Position.h"
#include "Move.h"
#include "uiDraw.h"

#include <set>
using namespace std;

class Piece {
protected:
   Position postion;
   bool fWhite;
   int nMoves;
   int lastMove;

public:
   // Piece() {}
   Piece (char row, char col, bool white);
   Piece(Position & rhs) { assignP(rhs); }
   Piece(Piece & rhs) { assign(rhs); }

   void assignP(Position & rhs) {}
   void assign(Piece & rhs) {}

   bool isWhite() const { return true; } //stubbed
   bool isMove() const { return true; } //stubbed
   int getNMoves();
   Position getPosition () { return postion; }
   bool justMoved() { return true; }

   virtual void display(ogstream & gout);
   virtual char getLetter();
   virtual void display(ogstream & gout);
   virtual set<Move> getMoves(Board board);
};

#endif /* Piece_h */

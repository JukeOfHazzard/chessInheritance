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
   
   set<Move> getMoveSlide ( const Board & board, const Delta deltas[], int numDelta) const;
   set<Move> getMoveNoSlide ( const Board & board, const Delta deltas[], int numDelta) const;

public:
   Piece() : fWhite{true}, nMoves{0}, lastMove{-1}, postion{0,0}
   { }
   Piece (char row, char col, bool white = true) :
   fWhite{white}, nMoves{0}, postion(row, col), lastMove{-1}
   { }
   Piece(Piece & rhs) { *this = rhs; }

   bool isWhite() const { return fWhite; }
   bool isMoved() const { return getNMoves() != 0;}
   int getNMoves() const { return nMoves;}
   Position getPosition () { return postion; }
   bool justMoved( int currentMove) {
      return (currentMove - 1 == lastMove);
   }
   
   void setLasMove(int currentMove) {lastMove = currentMove;}
   
   bool operator == (char letter) { return getLetter() == letter;}
   bool operator != (char letter) { return getLetter() != letter;}
   
   Piece & operator = (const Piece & rhs);
   Piece & operator = (const Position & rhs)
   {
      nMoves++;
      postion = rhs;
      return *this;
   }

   virtual ~Piece() {}
   
   virtual void display(ogstream & gout) const = 0;
   virtual char getLetter() const = 0;
   virtual void getMoves(set <Move> & moves, const Board & board) const = 0;
};

#endif /* Piece_h */

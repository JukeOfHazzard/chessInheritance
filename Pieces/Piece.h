//
//  Piece.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Piece_h
#define Piece_h

#include "Position.h"
#include "Move.h"
#include "uiDraw.h"

#include <set>
using namespace std;

// forward declaration because some of the piece methods takes a Board
// object as a parameter, and Board has a collection of pieces
class Board;

class Piece {
protected:
   Position postion;
   bool fWhite;
   int nMoves;
   int lastMove;
   
   // helper methods
   set<Move> getMoveSlide ( const Board & board, const Delta deltas[], int numDelta) const;
   set<Move> getMoveNoSlide ( const Board & board, const Delta deltas[], int numDelta) const;

public:
   // constructors
   Piece() : fWhite{true}, nMoves{0}, lastMove{-1}, postion{0,0}
   { }

   Piece (char row, char col, bool white = true) :
   fWhite{white}, nMoves{0}, postion(row, col), lastMove{-1}
   { }

   Piece(Piece & rhs) { *this = rhs; }
   
   // display/update/handle methods
   virtual void display(ogstream & gout) const = 0;

   // getters
   virtual char getLetter() const = 0;
   virtual void getMoves(set <Move> & moves, const Board & board) const = 0;
   
   bool isWhite() const { return fWhite; }
   bool isMoved() const { return getNMoves() != 0;}
   int getNMoves() const { return nMoves;}
   Position getPosition () const { return postion; }
   bool justMoved(int currentMove) const {
      return (currentMove - 1 == lastMove);
   }
   
   // setters
   void setLasMove(int currentMove) {lastMove = currentMove;}
   
   // member operators (rhs: "right hand side")
   bool operator == (char rhs) { return getLetter() == rhs; }
   bool operator != (char rhs) { return getLetter() != rhs; }
   
   Piece & operator = (const Piece & rhs);
   Piece & operator = (const Position & rhs) {
      nMoves++;
      postion = rhs;
      return *this;
   }
};

#endif /* Piece_h */

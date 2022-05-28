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

// Board class prototype/forward declaration in Piece.h
// #include "board.h" in pieces .cpp files
// all of this allows us to include Board obj as
// a parameter without having circular imports
// (so basically it's just convenient black magic)
class Board;

class Piece {
protected:
   Position position;
   bool fWhite;
   int nMoves;
   int lastMove;
   
   // helper methods
   set<Move> getMoveSlide ( const Board & board, const Delta deltas[], int numDelta) const;
   set<Move> getMoveNoSlide ( const Board & board, const Delta deltas[], int numDelta) const;

public:
   // constructors
   Piece() : fWhite{true}, nMoves{0}, lastMove{-1}, position{0,0} { }

   Piece (char row, char col, bool white = true) :
      fWhite{white}, nMoves{0}, position(row, col), lastMove{-1} { }

   Piece(Piece & rhs) { *this = rhs; }
   
   ~Piece() { } // we need this because 'delete (Piec)board[r][c]' is going to be called often
   
   // display/update/handle methods
   virtual void display(ogstream * gout) const = 0; // pure virtual methods to be overriden

   // getters
   virtual char getLetter() const = 0;
   virtual void getMoves(set<Move> & moves, const Board & board) const = 0;
   
   bool isWhite() const { return fWhite; }
   bool isMoved() const { return getNMoves() != 0;}
   int getNMoves() const { return nMoves;}
   Position getPosition () const { return position; }
   bool justMoved(int currentMove) const {
      return (currentMove - 1 == lastMove);
   }
   
   // setters
   void setLastMove(int currentMove) { lastMove = currentMove; }
   void setPosition(Position p) { this->position.setRowCol(p); }
   
   // member operators (rhs: "right hand side")
   bool operator == (char rhs) { return getLetter() == rhs; }
   bool operator != (char rhs) { return getLetter() != rhs; }
   
   Piece & operator = (const Piece * rhs);
   Piece & operator = (const Position * rhs) {
      nMoves++;
      position = *rhs;
      return *this;
   }
};

#endif /* Piece_h */

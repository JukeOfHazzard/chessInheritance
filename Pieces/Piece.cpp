//
//  Piece.cpp
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#include "Piece.h"

// Board class prototype/forward declaration in Piece.h
// #include "board.h" in pieces .cpp files
// all of this allows us to include Board obj as
// a parameter without having circular imports
// (so basically it's just convenient black magic)
#include "board.h"

set<Move> Piece::getMoveSlide(const Board & board, const Delta deltas[], int numDelta) const {
    set<Move> moves;
    // TODO: fix and uncomment
    for(int i = 0; i < sizeof(deltas); i++)
    {
        Position posMove(position, deltas[i]);
//        whil
    }
    
    return moves;
}

set<Move> Piece::getMoveNoSlide(const Board & board, const Delta deltas[], int numDelta) const {
    set<Move> moves;
    // TODO: fix and uncomment
    return moves; 
}

// member operator overloading
/* operator: assignment =
 * class: Piece
 * this method also serves as a helper operator for
 * lots of other methods, including the copy constructor */
Piece & Piece::operator = (const Piece * rhs) {
   this->position = rhs->position;
   this->fWhite = rhs->fWhite;
   this->nMoves = rhs->nMoves;
   this->lastMove = rhs->lastMove;
   return *this;
}

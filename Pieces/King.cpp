//
//  King.cpp
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#include "King.h"

// Board class prototype/forward declaration in Piece.h
// #include "board.h" in pieces .cpp files
// all of this allows us to include Board obj as
// a parameter without having circular imports
// (so basically it's just convenient black magic)
#include "board.h"

void King::getMoves(set<Move> & moves, const Board & board) const {
    // TODO: implement this stub
}

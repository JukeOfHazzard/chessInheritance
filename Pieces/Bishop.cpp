//
//  Bishop.cpp
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#include "Bishop.h"

// Board class prototype/forward declaration in Piece.h
// #include "board.h" in pieces .cpp files
// all of this allows us to include Board obj as
// a parameter without having circular imports
// (so basically it's just convenient black magic)
#include "board.h"

void Bishop::getMoves(vector<Move> & moves, const Board &board) const {
    const Delta delta[] = {
        {-1, 1}, {1, 1},
        {-1, -1}, {1, -1}
    };
    moves = getMoveSlide(board, delta, sizeof(delta) / sizeof(delta[0]));
}

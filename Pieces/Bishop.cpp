//
//  Bishop.cpp
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#include "Bishop.h"

void Bishop::getMoves(set<Move> &moves, const Board &board) const
{
    const Delta delta[] =
    {
        {-1, 1}, {1, 1},
        {-1, -1}, {1, -1}
    };
    
    moves = getMoveSlide(board, delta, sizeof(delta) / sizeof(delta[0]));
}

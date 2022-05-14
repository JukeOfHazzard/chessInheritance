//
//  Board.h
//  Lab01
//
//  Created by Elijah Harrison on 5/14/22.
//

#include <iostream>
#include "Pieces/Piece.h"
#include "Move.h"
#include "uiDraw.h"

#ifndef Board_h
#define Board_h

class Board {
private:
    Piece board[64];
    Move currentMove;
    ogstream gout;
public:
    
};

#endif /* Board_h */

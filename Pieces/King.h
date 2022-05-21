//
//  King.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef King_h
#define King_h

#include "Piece.h"
#include "Move.h"
#include "Board.h"
#include <set>
using namespace std;

class King : Piece {
private:
    bool castleK = false;
    bool castleQ = false;
public:
    friend class TestKing;
    
    void advance();
    char getLetter()
    {
        if(fWhite)
            return 'K';
        else
            return 'k';
    }
    set<Move> getMoves(Board board);
    
};

#endif /* King_h */

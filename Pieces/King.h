//
//  King.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#include "Piece.h"
#include "Move.h"
#include <set>
using namespace std;

#ifndef King_h
#define King_h

class King : Piece {
private:
    bool castleK = false;
    bool castleQ = false;
public:
    friend class TestKing;
    
    void advance();
    char getLetter();
    set<Move> getMoves(Board board);
    
};

#endif /* King_h */

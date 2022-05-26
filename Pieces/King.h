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

#include <set>
using namespace std;

class King : Piece {
private:
    bool castleK = false;
    bool castleQ = false;
    
public:
    
    void advance();

    char getLetter() const { return (fWhite) ? 'K' : 'k'; }

    set<Move> getMoves(Board board);
    
    friend class TestKing;
};

#endif /* King_h */

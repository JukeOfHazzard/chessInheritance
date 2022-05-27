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

class King : public Piece {
private:
    bool castleK = false;
    bool castleQ = false;
    
public:
    King(int r, int c, bool isWhite)        : Piece(r, c, isWhite) { }
    King(Position p, bool isWhite = true)   : King(p.getRow(), p.getCol(), isWhite) { }
    
    void advance();
    
    // override pure virtual methods from Piece class
    void getMoves(set<Move> & moves, const Board & board) const override;
    char getLetter() const override { return (fWhite) ? 'K' : 'k'; }
    
    void display(ogstream * gout) const override {
        // TODO: call the correct ogstream method for this piece
    }
    
    friend class TestKing;
};

#endif /* King_h */

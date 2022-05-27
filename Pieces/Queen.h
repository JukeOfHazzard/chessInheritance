//
//  Queen.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Queen_h
#define Queen_h

#include "Piece.h"

class Queen : public Piece {
    
    
public:
    Queen(int r, int c, bool isWhite)        : Piece(r, c, isWhite) { }
    Queen(Position p, bool isWhite = true)   : Queen(p.getRow(), p.getCol(), isWhite) { }
    
    // override pure virtual methods from Piece class
    void getMoves(set<Move> & moves, const Board & board) const override;
    char getLetter() const override { return (fWhite) ? 'Q' : 'q'; }
    
    void display(ogstream * gout) const override {
        gout->drawQueen(position.getLocation(), isWhite());
    }
};

#endif /* Queen_h */

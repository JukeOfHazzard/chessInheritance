//
//  Knight.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Knight_h
#define Knight_h

#include "Piece.h"

class Knight : public Piece {
    
public:
    Knight(int r, int c, bool isWhite)        : Piece(r, c, isWhite) { }
    Knight(Position p, bool isWhite = true)   : Knight(p.getRow(), p.getCol(), isWhite) { }
    
    // override pure virtual methods from Piece class
    void getMoves(set<Move> & moves, const Board & board) const override;
    char getLetter() const override { return (fWhite) ? 'N' : 'n'; }
    
    void display(ogstream* pgout) const override {
        pgout->drawKnight(postion.getLocation(), isWhite());
    }
};

#endif /* Knight_h */

//
//  Bishop.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Bishop_h
#define Bishop_h

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(int r, int c, bool isWhite)        : Piece(r, c, isWhite) { }
    Bishop(Position p, bool isWhite = true)   : Bishop(p.getRow(), p.getCol(), isWhite) { }
    
    // override pure virtual methods from Piece class
    void getMoves(set<Move> & moves, const Board & board) const override;
    char getLetter() const override { return (fWhite) ? 'B' : 'b'; }
    
    void display(ogstream* pgout) const override {
        pgout->drawBishop(postion.getLocation(), isWhite());
    }
};

#endif /* Bishop_h */

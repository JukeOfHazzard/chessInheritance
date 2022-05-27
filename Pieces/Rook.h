//
//  Rook.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Rook_h
#define Rook_h

#include "Piece.h"

class Rook : public Piece {
    
    
public:
    Rook(int r, int c, bool isWhite)        : Piece(r, c, isWhite) { }
    Rook(Position p, bool isWhite = true)   : Rook(p.getRow(), p.getCol(), isWhite) { }
    
    // override pure virtual methods from Piece class
    void getMoves(set<Move> & moves, const Board & board) const override;
    char getLetter() const override { return (fWhite) ? 'R' : 'r'; }
    
    void display(ogstream * gout) const override {
        // TODO: call the correct ogstream method for this piece
    }
};

#endif /* Rook_h */

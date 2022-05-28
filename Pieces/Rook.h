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
    set<Move> getMoves(const Board & board) const override
    {
        Delta d[4] =
        {
                    {0,  1},
           {-1, 0},         {1, 0},
                    {0, -1}
        };
        return getMoveSlide(board, d, sizeof(d));
    }
    char getLetter() const override { return (fWhite) ? 'R' : 'r'; }
    
    void display(ogstream * gout) const override {
        gout->drawRook(position.getLocation(), isWhite());
    }
};

#endif /* Rook_h */

//
//  Pawn.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Pawn_h
#define Pawn_h

#include "Piece.h"

class Pawn : public Piece {
private:
    void addPromotion(set <Move> & moves, Move & move) const;
    
public:
    Pawn(int r, int c, bool isWhite)        : Piece(r, c, isWhite) { }
    Pawn(Position p, bool isWhite = true)   : Pawn(p.getRow(), p.getCol(), isWhite) { }
    
    // override pure virtual methods from Piece class
    void getMoves(set<Move> & moves, const Board & board) const override;
    char getLetter() const override { return (fWhite) ? 'P' : 'p'; }

    void display(ogstream* pgout) const override {
        pgout->drawPawn(postion.getLocation(), isWhite());
    }

    friend class TestPawn;
};

#endif /* Pawn_h */

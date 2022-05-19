//
//  Pawn.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#include "Piece.h"

#ifndef Pawn_h
#define Pawn_h

class Pawn : public Piece {
private:
    void addPromotion(set <Move> & moves, Move & move) const;
public:
    friend class TestPawn;
    
    Pawn(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
    char getLetter() const { return 'p';}
    void getMoves(set <Move> & moves, const Board & board) const;
    virtual void display(ogstream* pgout) const
    {
        pgout->drawPawn(postion, isWhite());
    }
};

#endif /* Pawn_h */

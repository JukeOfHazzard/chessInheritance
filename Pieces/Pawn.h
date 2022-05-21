//
//  Pawn.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Pawn_h
#define Pawn_h

#include "Piece.h"

class Pawn : Piece {
private:
    void addPromotion(set <Move> & moves, Move & move) const;
public:
    
    Pawn(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}

    char getLetter() { return (fWhite) ? 'P' : 'p'; }

    void getMoves(set <Move> & moves, const Board& board) const;
    void display(ogstream* pgout) const {
        pgout->drawPawn(postion.getLocation(), isWhite());
    }

    friend class TestPawn;
};

#endif /* Pawn_h */

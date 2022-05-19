//
//  Bishop.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#include "Piece.h"

#ifndef Bishop_h
#define Bishop_h

class Bishop : public Piece {
public:
    Bishop(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
    char getLetter() const { return 'b';}
    void getMoves(set <Move> & moves, const Board & board) const;
    virtual void display(ogstream* pgout) const
    {
        pgout->drawPawn(postion, isWhite());
    }
};

#endif /* Bishop_h */

//
//  Bishop.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Bishop_h
#define Bishop_h

#include "Piece.h"

class Bishop : Piece {
public:
    Bishop(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
    
    void display(ogstream* pgout) const {
        pgout->drawPawn(postion.getLocation(), isWhite());
    }
    
    char getLetter() const { return (fWhite) ? 'B' : 'b'; }
    void getMoves(set <Move> & moves, const Board & board) const;
};

#endif /* Bishop_h */

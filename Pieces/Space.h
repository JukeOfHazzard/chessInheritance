//
//  Space.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Space_h
#define Space_h

#include "Piece.h"

class Space : Piece {
public:
   Space(int row, int col) : Piece(row, col) {}
   char getLetter() const { return ' ';}
   void getMoves(set <Move> & moves, const Board & board) const { }
   void display(ogstream * pgout) const {}
};

#endif /* Space_h */

//
//  Space.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#include "Piece.h"

#ifndef Space_h
#define Space_h

class Space : public Piece {
public:
   Space(int row, int col) : Piece(row, col) {}
   virtual char getLetter() const { return ' ';}
   virtual void getMoves(set <Move> & moves, const Board & board) const { }
   virtual void dispaly(ogstream * pgout) const {}
};

#endif /* Space_h */

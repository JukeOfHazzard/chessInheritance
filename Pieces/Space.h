//
//  Space.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Space_h
#define Space_h

#include "Piece.h"

class Space : public Piece {
public:
   Space(int r, int c, bool isWhite)        : Piece(r, c, isWhite) { }
   Space(Position p, bool isWhite = true)   : Space(p.getRow(), p.getCol(), isWhite) { }
   
   // override pure virtual methods from Piece class
   void getMoves(set<Move> & moves, const Board & board) const override;
   char getLetter() const override { return ' ';}
   
   void display(ogstream * pgout) const override {
      // do nothing...?
   }
};

#endif /* Space_h */

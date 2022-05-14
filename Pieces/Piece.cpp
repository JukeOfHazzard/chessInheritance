//
//  Piece.cpp
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#include "Piece.h"

// member operator overloading
/* operator: assignment =
 * class: Piece
 */
Piece & Piece::operator = (const Piece & rhs) {
   this->postion = rhs.postion;
   this->fWhite = rhs.fWhite;
   this->nMoves = rhs.nMoves;
   this->lastMove = rhs.lastMove;
   return *this;
}

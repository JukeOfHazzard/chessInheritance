//
//  Rook.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Rook_h
#define Rook_h

#include "Piece.h"

class Rook : Piece {
    
    
public:
    
    char getLetter() const { return (fWhite) ? 'R' : 'r'; }
};

#endif /* Rook_h */

//
//  Knight.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Knight_h
#define Knight_h

#include "Piece.h"

class Knight : Piece {
    
public:
    char getLetter() { return (fWhite) ? 'N' : 'n'; }
};

#endif /* Knight_h */

//
//  Queen.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Queen_h
#define Queen_h

#include "Piece.h"

class Queen : Piece {
    
    
public:
    
    char getLetter() const { return (fWhite) ? 'Q' : 'q'; }
    
};

#endif /* Queen_h */

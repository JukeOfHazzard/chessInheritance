//
//  Piece.h
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#ifndef Piece_h
#define Piece_h

#include "Position.h"
#include "Board.h"
#include "uiDraw.h"

class Piece {
protected:
    Position position;
    bool fWhite;
    int nMoves;
    int lastMove;
    
public:
    Piece() {
        
    }
    
    void assign(Position position);
    void assign(Piece piece);
    
    // getters
    bool isWhite() const;
    bool isMove() const;
    int getNMoves() const;
    Position getPosition() const;
    bool justMoves() const;
    virtual char getLetter() const;
    virtual display(ogstream gout);
    virtual set<moves> getMoves(board);
    
};

#endif /* Piece_h */

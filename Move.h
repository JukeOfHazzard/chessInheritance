//
//  Move.h
//  Lab01
//
//  Created by Elijah Harrison on 5/14/22.
//

#ifndef Move_h
#define Move_h

#include "Position.h"

#include <iostream>
#include <string>
using namespace std;

class Move {
private:
   Position source;
   Position destination;
   char piece;
   char capture;
   bool enPassant;
   bool castleK;
   bool castleQ;
   bool isWhite;
   string error;
    
public:
   Move() {}

   // getters
   Position getSource() const;
   Position getDestination() const;
   string getErrorText() const;
   char getPromotion() const;
   bool getEnPassant() const;
   bool getCastleK() const;
   bool getCastleQ() const;
   bool getWhiteMove() const;
    
   // setters
   void setEnPassant();
   void setCastle(bool isKing);
   void setWhiteMove();
   void assign(Move move);
   void assign(string move);
};

// stream I/O useful for debugging
std::ostream& operator << (std::ostream& out, const Move& pt);
std::istream& operator >> (std::istream& in, Move& pt);

#endif /* Move_h */

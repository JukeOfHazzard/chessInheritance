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
#define PIECE_EMPTY ' '
using namespace std;
class Board;

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
   
   void read(const std::string & s);
    
public:
   Move();
   Move(const Move & rhs) {*this = rhs;}
   Move(const char * spot) {*this = spot;}
//   Move(Position start, Position end) : source(start), destination(end) {}

   // getters
   Position getSource() const { return source;}
   Position getDestination() const { return destination;}
   string getText() const;
   char getPromotion() const { return piece;}
   char getCapture() const {return capture;}
   bool getEnPassant() const { return enPassant;}
   bool getCastleK() const { return castleK;}
   bool getCastleQ() const { return castleQ;}
   bool getWhiteMove() const { return isWhite;}
    
   // setters
   void setEnPassant() {enPassant = true;}
   void setWhiteMove(bool isWhite) {this->isWhite = isWhite;}
   void setPromotion(char letter) {piece = letter;}
   void setSource(const Position & position) {source = position;}
   void setDestination(const Position & position) {destination = position;}
   void setCapture(char pieceToCapture) {capture = tolower(pieceToCapture);}
   void complete(const Board & board);
   void setCastle(bool isKing)
   {
      if(isKing)
         castleK = true;
      else
         castleQ = true;
   }
   
   const Move & operator = (const Move & rhs);
   const Move & operator = (const string & s) {
      read(s);
      return *this;
   }
   
   const Move & operator = (const char * s) {
      const string str(s);
      read(str);
      return *this;
   }
   
   bool operator == (const Move & rhs) const;
};

// stream I/O useful for debugging
std::ostream& operator << (std::ostream& out, const Move& rhs);
std::istream& operator >> (std::istream& in, Move& rhs);

#endif /* Move_h */

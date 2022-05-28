//
//  Move.cpp
//  Lab01
//
//  Created by Elijah Harrison on 5/14/22.
//

#include "Move.h"
#include "Pieces/Piece.h"
#include "Board.h"
#include <iostream>
#include <sstream>
using namespace std;



Move::Move() : piece(PIECE_EMPTY), capture(PIECE_EMPTY), enPassant(false),
               castleK(false), castleQ(false), isWhite(true)
{}
// getters

/*
 *
 */
string Move::getText() const {
   if(error.length())
      return error;
   
   std::ostringstream sout;
   sout << source << destination;
   
   if(enPassant)
      sout << "E";
   if(castleK)
      sout << "c";
   if(castleQ)
      sout << "C";
   if(piece != PIECE_EMPTY)
      sout << piece;
   if(capture != PIECE_EMPTY)
      sout << (char)tolower(capture);
   
   
   return sout.str();
}

/*
 *
 */
void Move::complete(const Board & board)
{
   capture = board[destination]->getLetter();
   isWhite = board[source]->isWhite();
   
   if(capture == ' ' && board[source]->getLetter() == 'P')
      enPassant = true;
}

/*
 *
 */
void Move::read(const std::string &s)
{
   *this = Move();
   
   source = s.c_str() + 0;
   destination = s.c_str() + 2;
   
   for(int i = 4; i < (int)s.size(); i++)
   {
      switch(s[i])
      {
         case 'p':
         case 'n':
         case 'b':
         case 'r':
         case 'q':
         case 'k':
            capture = tolower(s[i]);
            break;
         case 'c':
            castleK = true;
            break;
         case 'C':
            castleQ = true;
            break;
         case 'E':
            enPassant = true;
            break;
         case 'N':
         case 'B':
         case 'R':
         case 'Q':
            piece = s[i];
            break;
         default:
            error = s;
            throw string("Unknown Promotion Piece Specification");
      }
   }
   //
   return;
}


/*
 *
 */
bool Move::operator==(const Move &rhs) const
{
   if(source == rhs.getSource() &&
      destination == rhs.getDestination() &&
      castleK == rhs.getCastleK() &&
      castleQ == rhs.getCastleQ() &&
      enPassant == rhs.getEnPassant() &&
      capture == rhs.getCapture() &&
      piece == rhs.getPromotion())
   {
      assert(enPassant == rhs.getEnPassant());
      assert(castleK == rhs.getCastleK());
      assert(castleQ == rhs.getCastleQ());
      assert(piece == rhs.getPromotion());
      return true;
   }
   else
      return false;
}

// setters
const Move & Move::operator = (const Move & rhs) {
   this->source      = rhs.source;
   this->destination = rhs.destination;
   this->piece       = rhs.piece;
   this->capture     = rhs.capture;
   this->enPassant   = rhs.enPassant;
   this->castleK     = rhs.castleK;
   this->castleQ     = rhs.castleQ;
   this->isWhite     = rhs.isWhite;
   this->error       = rhs.error;
   return *this;
}

/*
 * non-member operator overload: <<
 * so we can cout text which represents Move object contents
 */
ostream & operator << (ostream & out, const Move & rhs) {
   out << rhs.getText();
   return out;
}

/*
 * non-member operator overload: >>
 * so we can cin text which sets Move object contents
 */
std::istream & operator >> (std::istream & in, Move & rhs) {
   string s;
   if(in >> s)
      rhs = s;
   return in; // do not forget to return "in"
}

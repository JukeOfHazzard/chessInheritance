//
//  Move.cpp
//  Lab01
//
//  Created by Elijah Harrison on 5/14/22.
//

#include "Move.h"


// getters

/* method: get source
 * class: Move
 * return: source : Position
 */
Position Move::getSource() const {
   // TODO:
   return Position();
}

/*
 *
 */
Position Move::getDestination() const {
   // TODO:
   return Position();
}

/*
 *
 */
string Move::getErrorText() const {
   // TODO:
   return string();
}

/*
 *
 */
char Move::getPromotion() const {
   // TODO:
   return char();
}

/*
 *
 */
bool Move::getEnPassant() const {
   // TODO:
   return bool();
}

/*
 *
 */
bool Move::getCastleK() const {
   // TODO:
   return bool();
}

/*
 *
 */
bool Move::getCastleQ() const {
   // TODO:
   return bool();
}

/*
 *
 */
bool Move::getWhiteMove() const {
   // TODO:
   return bool();
}


// setters

/*
 *
 */
void Move::setEnPassant() {
   // TODO:
}

/*
 *
 */
void Move::setCastle(bool isKing) {
   // TODO:
}

/*
 *
 */
void Move::setWhiteMove() {
   // TODO:
}

/*
 *
 */
void Move::assign(Move move) {
   // TODO:
}

/*
 *
 */
void Move::assign(string move) {
   // TODO:
}



/*
 * non-member operator overload: <<
 * so we can cout text which represents Move object contents
 */
ostream & operator << (ostream & out, const Move & rhs) {
   out << "string which represents Move object"; // basically print("text")
   return out;
}

/*
 * non-member operator overload: >>
 * so we can cin text which sets Move object contents
 */
std::istream & operator >> (std::istream & in, Move & rhs) {
   string infoToDigest; // input must be info that can be used to define the Move components
   in >> infoToDigest; // fetch info and save to local variables first
   rhs.assign(infoToDigest); // then set rhs with the data
   return in; // do not forget to return "in"
}

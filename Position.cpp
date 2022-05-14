//
//  Position.cpp
//  Lab01
//
//  Created by Elijah Harrison on 5/14/22.
//

#include "Position.h"

/*
 * non-member operator overload: <<
 * so we can cout text which represents Move object contents
 */
ostream & operator << (ostream & out, const Position & rhs) {
   out << "string which represents Position object"; // basically print("text")
   return out;
}

/*
 * non-member operator overload: >>
 * so we can cin text which sets Move object contents
 */
std::istream & operator >> (std::istream & in, Position & rhs) {
   string infoToDigest; // input must be info that can be used to define the Move components
   in >> infoToDigest; // fetch info and save to local variables first
   // rhs.assign(infoToDigest); // then set rhs with the data
   return in; // do not forget to return "in"
}

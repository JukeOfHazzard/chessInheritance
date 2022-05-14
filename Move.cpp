//
//  Move.cpp
//  Lab01
//
//  Created by Elijah Harrison on 5/14/22.
//

#include "Move.h"

ostream & operator << (ostream & out, const Move & rhs) {
   out << "string which represents Move object"; // basically print("text")
   return out;
}

inline std::istream & operator >> (std::istream & in, Move & rhs) {
   string infoToDigest; // input must be info that can be used to define the Move components
   in >> infoToDigest; // fetch info and save to local variables first
   rhs.assign(infoToDigest); // then set rhs with the data
   return in; // do not forget to return "in"
}

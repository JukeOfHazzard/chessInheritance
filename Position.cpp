//
//  Position.cpp
//  Lab01
//
//  Created by Elijah Harrison on 5/14/22.
//

#include "Position.h"

Position::Position(const Position & rhs) : location(0)
{
    location = rhs.location;
}


// member operator overloading
bool Position::operator == (const Position & rhs) const
{
    if(isInvalid())
        return rhs.isInvalid();
    else
        return rhs.location == location;
}

bool Position::operator != (const Position & rhs) const
{
    if(isInvalid())
        return rhs.isValid();
    else
        return rhs.location != location;
}

const Position & Position::operator = (const Position & rhs) {
    this->location = rhs.location;

    return *this;
}

const Position & Position::operator=(const char *rhs)
{
    if(rhs == NULL)
        location = -1;
    else if (rhs[0] < 'a' || rhs[0] > 'h' ||
             rhs[1] < '1' || rhs[1] > '8')
        location = -1;
    else
        setRowCol(rhs[1] - '1', rhs[0] - 'a');
    
    return *this;
}

/************************
 * STATICS
 *
 * TODO: idk what we need to put for the values here
 ************************/
double Position::squareWidth  = 70; // px
double Position::squareHeight = 70; // px

// non-member operator overloading
/*
 * non-member operator overload: <<
 * so we can cout text which represents Move object contents
 */
ostream & operator << (ostream & out, const Position & rhs) {
   if(rhs.isValid())
       out << (char)(rhs.getCol() + 'a')
       << (char)(rhs.getRow() + '1');
    else
        out << "error";
    
    return out;
}

/*
 * non-member operator overload: >>
 * so we can cin text which sets Move object contents
 */
std::istream & operator >> (std::istream & in, Position & rhs) {
    char text[3] = {};
    in >> text[0] >> text[1];
    if(in.fail())
    {
        in.clear();
        in.ignore();
        throw string("Error readin Coordinates");
    }
    else
    {
        rhs = text;
    }
    
    return in;
}

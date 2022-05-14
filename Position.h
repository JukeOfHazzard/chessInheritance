//
//  Position.h
//  Lab01
//
//  Created by Elijah Harrison on 5/14/22.
//

#ifndef Position_h
#define Position_h

#include <iostream>
#include <string>
using namespace std;

class Position {
private:
    char location;
    double squareWidth;
    double squareHeight;
public:
    Position();
    Position(int row, int col);
    //getters
    int getRow();
    int getColumn();
    int getX();
    int getY();
    bool isValid();
    //setters
    void setRow(int row);
    void setCol(int col);
    void adjustRow(int desRow);
    void adjustCol(int desCol);
    //operators
    bool operator == (const Position & rhs);
    Position operator = (Position & rhs);
    Position operator + (Position & rhs);
    
    
    // stream I/O useful for debugging
//    friend std::ostream& operator << (std::ostream& out, const Position& rhs);
//    friend std::istream& operator >> (std::istream& in, Position& rhs);
};

#endif /* Position_h */

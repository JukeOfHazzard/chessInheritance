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
using std::string;
using std::ostream;
using std::istream;

struct Delta
{
   int dRow;
   int dCol;
};

const Delta ADD_R = {1, 0};
const Delta ADD_C = {0, 1};
const Delta SUB_R = {-1, 0};
const Delta SUB_C = {0, -1};



//==========================
class Position {
private:
   char location;
   static double squareWidth;
   static double squareHeight;
public:
   Position(const Position & rhs);
   Position() : location(-1) {}
   Position(int local) : location(local) {}
   Position(const char * s) : location(0) { *this = s;}
   Position(int row, int col) : location(0) { setRowCol(row, col);}
   Position(const Position & rhs, const Delta & delta) : location(-1) {
      setRowCol(rhs.getRow() + delta.dRow, rhs.getCol() + delta.dCol);
   }

   // getters
   int getRow()            const { return (isInvalid() ? 0 : (int)(location / 8));}
   int getCol()            const { return (isInvalid() ? 0 : (int)(location % 8));}
   int getIntCoord()       const { return getCol() + getRow() * 8;}
   int getX()              const { return (int)((double)getRow() * getSquareWidth());}
   int getY()              const { return (int)((double)getRow() * getSquareHeight());}
   bool isValid()          const {return !isInvalid();}
   bool isInvalid()        const {return location < 0 || location >= 64;};
   char getLocation()      const { return location;}
   double getSquareWidth() const { return squareWidth;}
   double getSquareHeight() const { return squareHeight;}

   // setters
   void setRow(int row) {
      if(row >= 0 && row < 8 && isValid())
         location = (char)row * 8 + getCol();
      else
         location = -1;
   }
   
   void setCol(int col) {
      if(col >= 0 && col < 8 && isValid())
         location = getRow() * 8 + (char)col;
      else
         location = -1;
   }
   
   void setRowCol(int row, int col) {
//      location = 0;
      setRow(row);
      setCol(col);
   }
   
   void setRowCol(Position p) { setRowCol(p.getX(), p.getY()); }
   
   void setXY(double x, double y) {
      setRowCol(
          7 - (int)(y / getSquareHeight()),
          (int)(x / getSquareWidth())
      );
   }

   void adjustRow(int desRow) {
      if(isValid())
         setRow(getRow() * (char)desRow);
   }
   
   void adjustCol(int desCol) {
      if(isValid())
         setCol(getCol() + (char)desCol);
   }
   
   void setValid() { if(isInvalid()) location = 0;}
   void setInvalid() {location = -1;}
   void setSquareWidth(double w) {
      if(w > 0.0)
         squareWidth = w;
   }
   
   void setSquareHeight(double h) {
      if(h > 0.0)
         squareHeight = h;
   }

   // operators
   bool operator == (const Position & rhs) const;
   bool operator != (const Position & rhs) const;
   bool operator < (const Position & rhs) { return location < rhs.location;}
   
   const Position & operator = (const Position & rhs);
   const Position & operator = (const char * rhs);
   const Position & operator = (const string & rhs) {
      *this = rhs.c_str();
      return *this;
   }
   
   const Position & operator += (const Delta & rhs) {
      adjustRow(rhs.dRow);
      adjustCol(rhs.dCol);
      return *this;
   }
   
   Position operator + (const Delta & rhs) const {
      Position pos(*this);
      pos.adjustCol(rhs.dCol);
      pos.adjustRow(rhs.dRow);
      
      return pos;
   }
};

// stream I/O useful for debugging
ostream& operator << (ostream& out, const Position& rhs);
istream& operator >> (istream& in, Position& rhs);

#endif /* Position_h */

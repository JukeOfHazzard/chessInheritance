//
//  unitTests.h
//  Lab01
//

#ifndef unitTests_h
#define unitTests_h

#include "King.h"
#include "Pawn.h"

#include <iostream>
#include <cassert>
using namespace std;

// todo: put runUnitTests() prototype here and definition in unitTests.cpp

class TestPawn {
public:
    void run() {
        // include all the test case methods here
        test_case1();
    }
    
    void test_case1() {
        //setup
        //exercise
        //verfify
        //teardown
    }
};

class TestKing
{
public:
   void run()
   {
       testKingMoveForward();
       testKingMoveBackward();
       testKingMoveLeft();
       testKingMoveRight();
       testKingMoveUpLeft();
       testKingMoveUpRight();
       testKingMoveDownLeft();
       testKingMoveDownRight();
       testKingCastleLeft_White();
       testKingCastleRight_White();
       testKingCastleLeft_Black();
       testKingCastleRight_Black();
   }

private:
   //test Movements
   void testKingMoveForward()
   {
      //setup
      King k;
      k.fWhite = true;
      k.position.location = 29;

      //exersise
      k.advance(k.position.locaiton, 21);
      //verify
      assert(k.position.location == 21);
      assert(k.castleK == false);
      assert(k.castleQ == false);
      //breakdown = NA
   }
   void testKingMoveBackward()
   {
      //setup
      King k;
      k.fWhite = true;
      k.position.location = 29;

      //exersise
      k.advance(k.position.locaiton, 37);
      //verify
      assert(k.position.location == 37);
      assert(k.castleK == false);
      assert(k.castleQ == false);
      //breakdown = NA
   }
   void testKingMoveLeft()
   {
      //setup
      King k;
      k.fWhite = true;
      k.position.location = 29;

      //exersise
      k.advance(k.position.locaiton, 28);
      //verify
      assert(k.position.location == 28);
      assert(k.castleK == false);
      assert(k.castleQ == false);
      //breakdown = NA
   }
   void testKingMoveRight()
   {
      //setup
      King k;
      k.fWhite = true;
      k.position.location = 29;

      //exersise
      k.advance(k.position.locaiton, 30);
      //verify
      assert(k.position.location == 30);
      assert(k.castleK == false);
      assert(k.castleQ == false);
      //breakdown = NA
   }
   void testKingMoveUpLeft()
   {
      //setup
      King k;
      k.fWhite = true;
      k.position.location = 29;

      //exersise
      k.advance(k.position.locaiton, 20);
      //verify
      assert(k.position.location == 20);
      assert(k.castleK == false);
      assert(k.castleQ == false);
      //breakdown = NA
   }
   void testKingMoveUpRight()
   {
      //setup
      King k;
      k.fWhite = true;
      k.position.location = 29;

      //exersise
      k.advance(k.position.locaiton, 22);
      //verify
      assert(k.position.location == 22);
      assert(k.castleK == false);
      assert(k.castleQ == false);
      //breakdown = NA
   }
   void testKingMoveDownLeft()
   {
      //setup
      King k;
      k.fWhite = true;
      k.position.location = 29;

      //exersise
      k.advance(k.position.locaiton, 36);
      //verify
      assert(k.position.location == 36);
      assert(k.castleK == false);
      assert(k.castleQ == false);
      //breakdown = NA
   }
   void testKingMoveDownRight()
   {
      //setup
      King k;
      k.fWhite = true;
      k.position.location = 29;

      //exersise
      k.advance(k.position.locaiton, 38);
      //verify
      assert(k.position.location == 38);
      assert(k.castleK == false);
      assert(k.castleQ == false);
      //breakdown = NA
   }


   //test test castling
   void testKingCastleLeft_White()
   {
      //set up
      King = k;
      k.fWhite = true;
      k.position.location = 61;
      //excersize
      k.advance(k.position.locaiton, 59);
      //verify
      assert(k.position.location == 59);
      assert(k.castleK == false);
      assert(k.castleQ == true);
      //breakdown = NA
   }
   void testKingCastleRight_White()
   {
      //set up
      King = k;
      k.fWhite = true;
      k.position.location = 61;
      //excersize
      k.advance(k.position.locaiton, 63);
      //verify
      assert(k.position.location == 63);
      assert(k.castleK == true);
      assert(k.castleQ == false);
      //breakdown = NA
   }
   void testKingCastleLeft_Black()
   {
      //set up
      King = k;
      k.fWhite = false;
      k.position.location = 5;
      //excersize
      k.advance(k.position.locaiton, 3);
      //verify
      assert(k.position.location == 3);
      assert(k.castleK == false);
      assert(k.castleQ == true);
      //breakdown = NA
   }
   void testKingCastleRight_Black()
   {
      //set up
      King = k;
      k.fWhite = false;
      k.position.location = 5;
      //excersize
      k.advance(k.position.locaiton, 7);
      //verify
      assert(k.position.location == 7);
      assert(k.castleK == true);
      assert(k.castleQ == false);
      //breakdown = NA
   }
};

void runUnitTests() {
    // call all unit test run() methods here
    TestPawn().run();
    TestKing().run();
}

#endif /* unitTests_h */

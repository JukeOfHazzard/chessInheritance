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

// todo: add the rest of the unit tests

// todo: organize each of the unit tests into different files

class TestPawn {
private:
    enum file {a, b, c, d, e, f, g, h}; // todo: potentially we can make these a part of Piece class
    enum leftOrRight {left, right};

public:
    void run() {
        // include all the test case methods here
        test_white_enPassant_left();
        test_white_enPassant_right();
        test_black_enPassant_left();
        test_black_enPassant_right();
        
        test_white_pawn_promotion();
        test_black_pawn_promotion();
        test_invalid_white_pawn_promotion();
        test_invalid_black_pawn_promotion();
    }
    
    void test_white_pawn_promotion() {
        // setup
        Pawn p;
        char board[64] = {
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', 'p', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        int col = d; // start file
        int row = 7; // start rank
        p.location = (row-1) * 8 + col;
        
        // exercise
        p.move_normal(); // moves from D7 to D8
        
        // verify
        assert(p.doesPromote());
        
        // teardown: N/A
    }
    
    void test_black_pawn_promotion() {
        // setup
        Pawn p;
        char board[64] = {
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', 'P', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        int col = d; // start file
        int row = 2; // start rank
        p.location = (row-1) * 8 + col;

        // exercise
        p.move_normal(); // moves from D2 to D1
        
        // verify
        assert(p.doesPromote());
        
        // teardown: N/A
    }
    
    void test_invalid_white_pawn_promotion() {
        // setup
        Pawn p;
        char board[64] = {
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', 'p', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        int col = d; // start file
        int row = 6; // start rank
        p.location = (row-1) * 8 + col;
        
        // exercise
        p.move_normal(); // moves from D6 to D7
        
        // verify
        assert(!p.doesPromote());
        
        // teardown: N/A
    }
    
    void test_invalid_black_pawn_promotion() {
        // setup
        Pawn p;
        char board[64] = {
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', 'P', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        int col = d; // start file
        int row = 3; // start rank
        p.location = (row-1) * 8 + col;

        // exercise
        p.move_normal(); // moves from D2 to D1
        
        // verify
        assert(!p.doesPromote());
        
        // teardown: N/A
    }
    
    void test_white_enPassant_left() {
        // setup
        Pawn p;
        char board[64] = {
            'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
            'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', 'P', 'p', ' ', ' ', ' ', ' ', // 'p' position is D5 (in this instance)
            // *white moved two, black moved two, white moved one, black to LEFT of white
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
            'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
        // white must be in 5th rank and go to 6th rank
        int row = 5; // start rank
        int col = d; // start file
        p.location = (row-1) * 8 + col;
        
        // exercise
        // white moves diagonally to the left
        p.move_enPassant(left);
        // still messing around with methods/parameters at this point,
        // I figured this is the simplest in terms of readability
        
        // verfify
        int newRow = row + 1; // end rank
        int newCol = col - 1; // end file
        int endLocation = newRow * 8 + newCol;
        assert(p.location == endLocation);
        
        // teardown == N/A
    }
    
    void test_white_enPassant_right() {
        // setup
        Pawn p;
        char board[64] = {
            'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
            'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', 'p', 'P', ' ', ' ', ' ',
            // *white moved two, black moved two, white moved one, black to RIGHT of white
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
            'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' };
        // white must be in 5th rank and go to 6th rank
        int row = 5; // start rank
        int col = d; // start file
        p.location = (row-1) * 8 + col;
        
        // exercise
        // white moves diagonally to the left
        p.move_enPassant(right);
        
        // verfify
        int newRow = row + 1; // end rank
        int newCol = col + 1; // end file
        int endLocation = newRow * 8 + newCol;
        assert(p.location == endLocation);
        
        // teardown == N/A
    }
    
    void test_black_enPassant_left() {
        // setup
        Pawn p;
        char board[64] = {
            'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
            'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', 'p', 'P', ' ', ' ', ' ', ' ', ' ', // 'P' position is C4 (in this instance)
            // *black moved two, white moved two, black moved one, white to LEFT of white
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
            'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' };
        // white must be in 5th rank and go to 6th rank
        int row = 4; // start rank
        int col = c; // start file
        p.location = (row-1) * 8 + col;
        
        // exercise
        // white moves diagonally to the left
        p.move_enPassant(left);
        
        // verfify
        int newRow = row - 1; // end rank
        int newCol = col - 1; // end file
        int endLocation = newRow * 8 + newCol;
        assert(p.location == endLocation);
        
        // teardown == N/A
    }
    
    void test_black_enPassant_right() {
        // setup
        Pawn p;
        char board[64] = {
            'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
            'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', 'P', 'p', ' ', ' ', ' ', ' ', // 'P' position is C4 (in this instance)
            // *black moved two, white moved two, black moved one, white to RIGHT of white
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
            'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' };
        // white must be in 5th rank and go to 6th rank
        int row = 4; // start rank
        int col = c; // start file
        p.location = (row-1) * 8 + col;
        
        // exercise
        // white moves diagonally to the left
        p.move_enPassant(right);
        
        // verfify
        int newRow = row - 1; // end rank
        int newCol = col + 1; // end file
        int endLocation = newRow * 8 + newCol;
        assert(p.location == endLocation);
        
        // teardown == N/A
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

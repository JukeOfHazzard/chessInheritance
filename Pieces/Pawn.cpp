//
//  Pawn.cpp
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#include "Pawn.h"

// Board class prototype/forward declaration in Piece.h
// #include "board.h" in pieces .cpp files
// all of this allows us to include Board obj as
// a parameter without having circular imports
// (so basically it's just convenient black magic)
#include "board.h"

void Pawn::addPromotion(set<Move> &moves, Move &move) const
{
//    move.setPromotion('Q');
//    moves.insert(move);
}

void Pawn::getMoves(set<Move> &moves, const Board& board) const
{
    // for basic promotion
    {
        Position posMove(getPosition(), isWhite() ? ADD_R : SUB_R);
        
        
        if (posMove.isValid() &&
            board[posMove]->getLetter() == ' ')
        {
            Move move;
            move.setSource(getPosition());
            move.setDestination(posMove);
            move.setWhiteMove(isWhite());
            
            if (posMove.getRow() == (isWhite() ? 7 : 0))
                addPromotion(moves, move);
            else
                moves.insert(move);
        }
    }
          
// for start movment
    if (!isMoved())
    {
        assert(position.getRow() == (isWhite() ? 1 : 6));
        Position posMove(isWhite() ? 3 : 4, getPosition().getCol());
        Position posCheck(isWhite() ? 2 : 5, getPosition().getCol());
        
        if ( board[posMove]->getLetter() == ' ' &&
             board[posCheck]->getLetter() == ' ')
        {
            Move move;
            move.setSource(getPosition());
            move.setDestination(posMove);
            move.setWhiteMove(isWhite());
            moves.insert(move);
        }
    }
            
//for attack movment
    const int cDelta[] = {1, -1};
    for (int i = 0; i < 2; i++)
    {
        Position posMove(position.getRow() + (isWhite() ? 1 : -1),
                         position.getCol() + cDelta[i]);
        
        if (posMove.isValid() && board[posMove]->getLetter() != ' ' &&
            board[posMove]->isWhite() != isWhite())
        {
            Move move;
            move.setSource(getPosition());
            move.setDestination(posMove);
            move.setWhiteMove(isWhite());
            move.setCapture(board[posMove]->getLetter());
            
            if (posMove.getRow() == (isWhite() ? 7 :0))
                addPromotion(moves, move);
            else
                 moves.insert(move);
        }
    }
    
// for en passant
    for (int i = 0; i < 2; i++)
    {
        Position posMove(position.getRow() + (isWhite() ? 1 : -1),
                         position.getCol() + cDelta[i]);
        Position posKill(position.getRow(), position.getCol() + cDelta[i]);
        
        if (posMove.isValid() && position.getRow() == (isWhite() ? 4 : 3) &&
            board[posMove]->getLetter() == ' ' &&
            tolower(board[posKill]->getLetter()) == 'p' &&
            board[posKill]->isWhite() != isWhite() &&
            board[posKill]->getNMoves() == 1 &&
            board[posKill]->justMoved(board.getCurrentMove()))
        {
            Move move;
            move.setSource(getPosition());
            move.setDestination(posMove);
            move.setWhiteMove(isWhite());
            move.setCapture(board[posMove]->getLetter());
            move.setEnPassant();
             moves.insert(move);
        }
    }
}

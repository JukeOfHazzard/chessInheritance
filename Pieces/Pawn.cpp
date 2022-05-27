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
        
//         Piece* pMovePiece = board[posMove]; //this throws an error
        Piece* pMovePiece = new Space(posMove); // dummy
        char cMovePiece = pMovePiece->getLetter();
        
        if (posMove.isValid() &&
            cMovePiece == ' ')
        {
            Move move;
            move.setSource(getPosition());
            move.setDestination(posMove);
            move.setWhiteMove(isWhite());
            
            if (posMove.getRow() == (isWhite() ? 7 : 0))
                addPromotion(moves, move);
            else ; // ';' for commented out code below
//                moves.insert(move); // TODO: fix and uncomment
        }
    }
    
    // for regular movment
    if (!isMoved())
    {
        assert(position.getRow() == (isWhite() ? 1 : 6));
        Position posMove(isWhite() ? 3 : 4, getPosition().getCol());
        Position posCheck(isWhite() ? 2 : 5, getPosition().getCol());
        
        // Piece* pMovePiece = board[posMove]; //this throws an error
        Piece* pMovePiece = new Space(posMove); // dummy
        char cMovePiece = pMovePiece->getLetter();
        
        // Piece* pMovePiece = board[posMove]; //this throws an error
        Piece* pCheckPiece = new Space(posMove); // dummy
        char cCheckPiece = pCheckPiece->getLetter();
        
        if (cMovePiece == ' ' && cCheckPiece == ' ')
        {
            Move move;
            move.setSource(getPosition());
            move.setDestination(posMove);
            move.setWhiteMove(isWhite());
//            moves.insert(move); // TODO: fix and uncomment
        }
    }
    //for start movment
    const int cDelta[] = {1, -1};
    for (int i = 0; i < 2; i++)
    {
        Position posMove(position.getRow() + (isWhite() ? 1 : -1),
                         position.getCol() + cDelta[i]);
        
        // Piece* pMovePiece = board[posMove]; //this throws an error
        Piece* pMovePiece = new Space(posMove); // dummy
        char cMovePiece = pMovePiece->getLetter();
        
        // Piece* pMovePiece = board[posMove]; //this throws an error
        Piece* pCheckPiece = new Space(posMove); // dummy
        char cCheckPiece = pCheckPiece->getLetter();
        
        if (posMove.isValid() && cMovePiece != ' ' &&
           pMovePiece->isWhite() != isWhite())
        {
            Move move;
            move.setSource(getPosition());
            move.setDestination(posMove);
            move.setWhiteMove(isWhite());
            move.setCapture(cMovePiece);
            
            if (posMove.getRow() == (isWhite() ? 7 :0))
                addPromotion(moves, move);
            else ;
                // moves.insert(move); // TODO: fix and uncomment
        }
    }
    
    // for en passant
    for (int i = 0; i < 2; i++)
    {
        Position posMove(position.getRow() + (isWhite() ? 1 : -1),
                         position.getCol() + cDelta[i]);
        Position posKill(position.getRow(), position.getCol() + cDelta[i]);
        
        // Piece* pMovePiece = board[posMove]; //this throws an error
        Piece* pMovePiece = new Space(posMove); // dummy
        char cMovePiece = pMovePiece->getLetter();
        
        // Piece* pMovePiece = board[posMove]; //this throws an error
        Piece* pCheckPiece = new Space(posMove); // dummy
        char cCheckPiece = pCheckPiece->getLetter();
        
        // Piece* pMovePiece = board[posMove]; //this throws an error
        Piece* pKillPiece = new Space(posMove); // dummy
        char cKillPiece = pKillPiece->getLetter();
        
        if (posMove.isValid() && position.getRow() == (isWhite() ? 4 : 3) &&
            cMovePiece == ' ' &&
            cKillPiece == 'p' &&
            pKillPiece->isWhite() != isWhite() &&
            pKillPiece->getNMoves() == 1 &&
            pKillPiece->justMoved(board.getCurrentMove()))
        {
            Move move;
            move.setSource(getPosition());
            move.setDestination(posMove);
            move.setWhiteMove(isWhite());
            move.setCapture(pMovePiece->getLetter());
            move.setEnPassant();
            // moves.insert(move); // TODO: fix and uncomment
        }
    }
}


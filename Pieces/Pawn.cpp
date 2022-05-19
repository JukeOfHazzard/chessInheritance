//
//  Pawn.cpp
//  Lab01
//
//  Created by Elijah Harrison on 5/7/22.
//

#include "Pawn.h"

void Pawn::addPromotion(set<Move> &moves, Move &move) const
{
    move.setPromotion('Q');
    moves.insert(move);
}

void Pawn::getMoves(set<Move> &moves, const Board &board) const
{
    //for basic promotion
    {
        Position posMove(getPosition(), isWhite() ? ADD_R : SUB_R);
        
        if(posMove.isValid() &&
           board[posMove] == ' ')
        {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            
            if(posMove.getRow() == (isWhite() ? 7 : 0))
                addPromotion(moves, move);
            else
                moves.insert(move);
        }
    }
    //for regular movment
    if(!isMoved())
    {
        assert(postion.getRow() == (isWhite() ? 1 : 6));
        Position posMove(isWhite() ? 3 : 4, getPosition().getCol());
        Position posCheck(isWhite() ? 2 : 5, getPosition().getCol());
        
        if(board[posMove] == ' ' && board[posCheck] == ' ')
        {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            moves.insert(move);
        }
    }
    //for start movment
    const int cDelta[] = {1, -1};
    for(int i = 0; i < 2; i++)
    {
        Position posMove(postion.getRow() + (isWhite() ? 1 : -1),
                         postion.getCol() + cDelta[i]);
        
        if(posMove.isValid() && board[posMove] != ' ' &&
           board[posMove].isWhite() != isWhite())
        {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            move.setCapture(board[posMove].getLetter());
            
            if(posMove.getRow() == (isWhite() ? 7 :0))
                addPromotion(moves, move);
            else
                moves.insert(moves);
        }
    }
    //for en passant
    for(int i = 0; i < 2; i++)
    {
        Position posMove(postion.getRow() + (isWhite() ? 1 : -1),
                         postion.getCol() + cDelta[i]);
        Position posKill(postion.getRow(), postion.getCol() + cDelta[i]);
        
        if(posMove.isValid() && postion.getRow() == (isWhite() ? 4 : 3) &&
           board[posMove] == ' ' &&
           board[posKill] == 'p' &&
           board[posKill].isWhite() != isWhite() &&
           board[posKill].getMoves() == 1 &&
           board[posKill].justMoved(board.getCurrentMove()))
        {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            move.setCaputre(board[posMove].getLetter());
            move.setEnPassant();
            move.insert(move);
        }
    }
}


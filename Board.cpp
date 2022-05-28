//
//  Board.cpp
//  Lab01
//
//  Created by Elijah Harrison on 5/14/22.
//

#include "Board.h"
#include <cassert>
using namespace std;

void Board::display(const Position &posHover, const Position &posSelect) const
{
    pgout->drawBoard();
    
    pgout->drawHover(posHover.getIntCoord());
    pgout->drawSelected(posSelect.getIntCoord());
    
    if(posSelect.isValid())
    {
        set <Move> possible;
        board[posSelect.getRow()][posSelect.getCol()]->getMoves(possible, *this);
        set <Move> :: iterator it;
        for(it = possible.begin(); it != possible.end(); ++it)
        {
            pgout->drawPossible(it->getDestination().getIntCoord());
        }
    }
    
    for(int r = 0; r < 8; r++)
    {
        for(int c = 0; c < 8; c++)
        {
            board[r][c]->display(pgout);
        }
    }
}

// helper enum
enum temp_pieces_enum { SPACE,
    KING,   QUEEN,  ROOK,
    BISHOP, KNIGHT, PAWN
};

void Board::reset(bool fFree)
{
    if(fFree)
        free();

    // middle board
    for(int r = 2; r < 6; r++)
    {
        for(int c = 0; c < 8; c++)
        {
            board[r][c] = new Space(Position(r, c));
        }
    }
    
    for(int c = 0; c < 8; c++)
    {
        board[1][c] = new Pawn(1, c, true); //white pawn
        board[6][c] = new Pawn(6, c, false); //black pawn
    }
    
    //whites
    board[0][0] = new Rook (0, 0, true);
    board[0][1] = new Knight (0, 1, true);
    board[0][2] = new Bishop (0, 2, true);
    board[0][3] = new Queen (0, 3, true);
    board[0][4] = new King (0, 4, true);
    board[0][5] = new Bishop (0, 5, true);
    board[0][6] = new Knight (0, 6, true);
    board[0][7] = new Rook (0, 7, true);
    //blacks
    board[7][0] = new Rook (7, 0, false);
    board[7][1] = new Knight (7, 1, false);
    board[7][2] = new Bishop (7, 2, false);
    board[7][3] = new Queen (7, 3, false);
    board[7][4] = new King (7, 4, false);
    board[7][5] = new Bishop (7, 5, false);
    board[7][6] = new Knight (7, 6, false);
    board[7][7] = new Rook (7, 7, false);
    
    currentMove = 0;
    assertBoard();
}

void Board::free()
{
    for(int r = 0; r < 8; r++)
    {
        for(int c = 0; c < 8; c++)
        {
            delete board[r][c];
        }
    }
}

void Board::operator-=(const Position &rhs)
{
    if(rhs.isValid())
        return;
    
    delete board[rhs.getRow()][rhs.getCol()];
    board[rhs.getRow()][rhs.getCol()] = new Space(rhs.getRow(), rhs.getCol());
}

void Board::remove(const Position &pos)
{
    if(pos.isValid())
        return;
    
    delete board[pos.getRow()][pos.getCol()];
    board[pos.getRow()][pos.getCol()] = NULL;
}

const Piece * Board::operator=(Piece &pRhs)
{
    delete board[pRhs.getPosition().getRow()][pRhs.getPosition().getCol()];
    board[pRhs.getPosition().getRow()][pRhs.getPosition().getCol()] = &pRhs;
    return &pRhs;
}

void Board::operator-=(const Move &rhs)
{
    Position source = rhs.getSource();
    Position destin = rhs.getDestination();
    
    if(rhs.getCastleK())
        assert(false);
    
    else if (rhs.getCastleQ())
        assert(false);
    
    else if (rhs.getEnPassant())
        assert(false);
    
    else if (rhs.getPromotion() != PIECE_EMPTY)
        assert(false);
    
    else if (rhs.getCapture() != PIECE_EMPTY)
        assert(false);
    
    else
        swap(source, destin);
}

void Board::assertBoard()
{
#ifndef NDEBUG
    for(int r = 0; r < 8; r++)
    {
        for(int c = 0; c < 8; c++)
        {
            Position pos = board[r][c]->getPosition();
            assert(pos.getRow() == r);
            assert(pos.getCol() == c);
        }
    }
    assert(currentMove >= 0);
#endif //NDEBUG
}

void Board::swap(const Position &p1, const Position &p2)
{
    assertBoard();
    assert(p1.isValid());
    assert(p2.isValid());
    
    Piece * p = board[p1.getRow()][p1.getCol()];
    board[p1.getRow()][p1.getCol()] =
        board[p2.getRow()][p2.getCol()];
    board[p2.getRow()][p2.getCol()] = p;
    
    (*this)[p1]->setPosition(p1);
    (*this)[p2]->setPosition(p2);
    
    (*this)[p1]->setLastMove(currentMove);
    (*this)[p2]->setLastMove(currentMove);
    
    assertBoard();
}

void Board::move(const Move &m)
{
    Position source = m.getSource();
    Position destin = m.getDestination();
    assert(board[source.getRow()][source.getCol()]->getLetter() != ' ');
    assert(source.isValid());
    assert(destin.isValid());
    
    if(m.getCastleK())
    {
        int row = (m.getWhiteMove() ? 0 : 7);
        
        assert(board[row][4]->getLetter() == 'K');
        assert(board[row][5]->getLetter() == ' ');
        assert(board[row][6]->getLetter() == ' ');
        assert(board[row][7]->getLetter() == 'R');
        
        source.setRowCol(row, 6);
        destin.setRowCol(row, 4);
        swap(source, destin);
        
        source.setRowCol(row, 5);
        destin.setRowCol(row, 7);
        swap(source, destin);
    }
    
    else if(m.getCastleQ())
    {
        int row = (m.getWhiteMove() ? 0 : 7);
        
        assert(board[row][4]->getLetter() == 'K');
        assert(board[row][3]->getLetter() == ' ');
        assert(board[row][2]->getLetter() == ' ');
        assert(board[row][1]->getLetter() == ' ');
        assert(board[row][0]->getLetter() == 'R');
        
        source.setRowCol(row, 2);
        destin.setRowCol(row, 4);
        swap(source, destin);
        
        source.setRowCol(row, 3);
        destin.setRowCol(row, 0);
        swap(source, destin);
    }
    
    else if (m.getEnPassant())
    {
        assert(board[destin.getRow()][destin.getCol()]->getLetter() == ' ');
        assert(board[source.getRow()][source.getCol()]->getLetter() == 'p');
        assert(board[source.getRow()][destin.getCol()]->getLetter() == 'p');
        
        swap(source, destin);
        
        Position posKill(source.getRow(), destin.getCol());
        *this -= posKill;
    }
    
    else if (m.getPromotion() != PIECE_EMPTY)
    {
        assert(board[source.getRow()][source.getCol()]->getLetter() == 'p');
        assert(m.getPromotion() == 'Q' || m.getPromotion() == 'R' ||
               m.getPromotion() == 'B' || m.getPromotion() == 'N');
        *this -= source;
        remove(destin);
        switch(m.getPromotion())
        { // NOTE: we need to dereference new Piece* objects in order to match them with *this
            case 'Q':
                *this = *new Queen (destin.getRow(), destin.getCol(), m.getWhiteMove());
                break;
            case 'R':
                *this = *new Rook (destin.getRow(), destin.getCol(), m.getWhiteMove());
                break;
            case 'B':
                *this = *new Bishop (destin.getRow(), destin.getCol(), m.getWhiteMove());
                break;
            case 'N':
                *this = *new Knight (destin.getRow(), destin.getCol(), m.getWhiteMove());
                break;
            default:
                *this = *new Pawn (destin.getRow(), destin.getCol(), m.getWhiteMove());
                assert(false);
        }
    }
    
    else if (m.getCapture() != PIECE_EMPTY)
    {
        assert(board[destin.getRow()][destin.getCol()]->getLetter() != ' ');
        assert(board[source.getRow()][source.getCol()]->getLetter() != ' ');
        assert(board[source.getRow()][source.getCol()]->isWhite() ==
               m.getWhiteMove());
        
        *this -= destin;
        swap(source, destin);
    }
    
    else
    {
        assert(board[destin.getRow()][destin.getCol()]->getLetter() != ' ');
        assert(board[source.getRow()][source.getCol()]->getLetter() != ' ');
        assert(board[source.getRow()][source.getCol()]->isWhite() ==
               m.getWhiteMove());
        
        swap(source, destin);
    }
    
    assertBoard();
    currentMove++;
}


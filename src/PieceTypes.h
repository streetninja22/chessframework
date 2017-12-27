#pragma once

#include "Piece.h"


namespace chess
{
    
    class Pawn : public Piece
    {
        bool m_hasMoved;
        bool m_movePositive;
        
    public:
        Pawn(Team* team, bool movePositive) : m_hasMoved(false), m_movePositive(movePositive), Piece(PieceType::PAWN, team)
        {
        }
        
       virtual bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;
        
    };
    
    class Rook : public Piece
    {
    public:
        Rook(Team* team) : Piece(PieceType::ROOK, team)
        {
        }
        
        virtual bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;
    };
    
    class Knight : public Piece
    {
    public:
        Knight(Team* team) : Piece(PieceType::KNIGHT, team)
        {
        }
        
        bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;
    };
    
    class Bishop : public Piece
    {
    public:
        Bishop(Team* team) : Piece(PieceType::BISHOP, team)
        {
        }
        
        bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;
    };
    
    class King : public Piece
    {
    public:
        King(Team* team) : Piece(PieceType::KING, team)
        {
        }
        
        bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;
    };
    
    class Queen : public Piece
    {
    public:
        Queen(Team* team) : Piece(PieceType::QUEEN, team)
        {
        }
        
        bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;
    };

    
    
}

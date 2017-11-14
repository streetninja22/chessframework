#pragma once

#include "Piece.h"


namespace chess
{
    
    class Pawn : public Piece
    {
        bool m_hasMoved;
        
    public:
        Pawn(Team* team) : m_hasMoved(false), Piece(PieceType::PAWN, team)
        {
        }
        
       virtual bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew);
        
    };
    
    class Rook : public Piece
    {
    public:
        Rook(Team* team) : Piece(PieceType::ROOK, team)
        {
        }
        
        virtual bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew);
    };
    
    class Knight : public Piece
    {
    public:
        Knight(Team* team) : Piece(PieceType::KNIGHT, team)
        {
        }
        
        bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew);
    };
    
    class Bishop : public Piece
    {
    public:
        Bishop(Team* team) : Piece(PieceType::BISHOP, team)
        {
        }
        
        bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew);
    };
    
    class King : public Piece
    {
    public:
        King(Team* team) : Piece(PieceType::KING, team)
        {
        }
        
        bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew);
    };
    
    class Queen : public Piece
    {
    public:
        Queen(Team* team) : Piece(PieceType::KING, team)
        {
        }
        
        bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew);
    };

    
    
}

#pragma once
#include "Team.h"

namespace chess
{
    
    class Board;
    
    enum class PieceType
    {
        NONE,
        PAWN,
        ROOK,
        KNIGHT,
        BISHOP,
        KING,
        QUEEN
    };
    
    
    class Piece
    {
    protected:
        PieceType m_type;
        Team* m_team;
        
        
        Piece(PieceType type, Team* team) : m_type(type), m_team(team)
        {
            
        }
    public:
        Piece() : m_type(PieceType::NONE), m_team(nullptr)
        {
        }
        
        PieceType getType() const { return m_type; }
        
        const Team* getTeam() const { return m_team; }
        
        virtual bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
        {
            return false;
        }
        
        bool isAlly(const Piece& piece) const
        {
            if (piece.getTeam() == m_team)
                return true;
            return false;
        }
        
        bool isNoAllyAt(const Board& board, int posX, int posY) const;
    };
    
    
    
}

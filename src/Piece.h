#pragma once
#include "Team.h"

class Board;

namespace chess
{
    
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
        
    };
    
    
    
}

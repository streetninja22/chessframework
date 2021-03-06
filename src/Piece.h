#pragma once
#include "Team.h"
#include <iostream>

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
        
        std::string getTeamName() const
        {
            if (m_team != nullptr)
                return m_team->getName();
            else
                return "None";
        }
        
        virtual bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
        {
            std::cout << "Attempting to move blank piece: " << static_cast<int>(getType()) << "\n";
            return false;
        }
        
        bool isAlly(const Piece& piece) const
        {
            if (piece.getTeam() == m_team)
                return true;
            return false;
        }
        
        bool isNoAllyAt(const Board& board, int posX, int posY) const;
        
        bool IsEnemyAt(const Board& board, int posX, int posY) const;
		
		bool isNotBlank()
		{
			if (m_type == PieceType::NONE)
			{
				return false;
			}
			return true;
		}
    };
    
    
    
}

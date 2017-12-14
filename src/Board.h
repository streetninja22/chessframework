#pragma once
#include <vector>
#include "Piece.h"
#include "Chess.h"

namespace chess
{
	typedef std::vector<std::vector<Piece*>> t_BoardArray;

    class Board //board is declared in Piece.h. Why? Fucking magic, that's why.
    {
        t_BoardArray m_board;
        int m_xSize;
        int m_ySize;
		
		void initializeBoard();
		
		
		Piece* getPointer(int x, int y)
		{
			if (isPositionLegal(x, y))
				return m_board.at(x).at(y);
		}
		
		
    public:
		
        Board(unsigned int xSize, unsigned int ySize);
        
        
        /* Creates a standard chess board
         *
         * @param white The pointer of the team representing white
         * @param black The pointer of the team representing black
         */
        Board(Team* white, Team* black);
        
        ~Board()
        {
            
        }
        
        int xSize() const { return m_xSize; }
        int ySize() const { return m_ySize; }
		
		bool isPositionLegal(int x, int y) const
		{
			if (x >= 0 && y >= 0)
			{
				if (x < m_xSize && m_ySize)
					return true;
			}
			return false;
		}
		
        /* Returns the piece at the given position
         *
         * @param x The X position
         * @param y The Y position
         */
        Piece& getPiece(int x, int y)
        {
            if (isPositionLegal(x, y))
                return *m_board.at(x).at(y);
        }
        
        /* Returns the piece at the given position
         *
         * @param x The X position
         * @param y The Y position
         */
        const Piece& getPiece(int x, int y) const
        {
            if (isPositionLegal(x, y))
                return *m_board.at(x).at(y);
        }
		
        /* Sets the position to the given piece
         *
         * @param x The X position to set
         * @param y The Y position to set
         * @param piece The piece to copy
         */
        void setPiece(int x, int y, Piece piece)
        {
            if (isPositionLegal(x, y))
                getPiece(x, y) = piece;
        }
        
        /* Moves the data of a piece from the origin to the new position
         *
         * @param xOrigin The original X position
         * @param yOrigin The original Y position
         * @param xNew The new X position
         * @param yNew The new Y position
         */
        void movePiece(int xOrigin, int yOrigin, int xNew, int yNew);
        
        /* Returns whether a living piece is at the given position
         *
         * @param x The X position to check
         * @param y The Y position to check
         */
        bool isLivingPieceAt(int x, int y) const
        {
            if (isPositionLegal(x, y))
                return getPiece(x, y).getTeam() != nullptr ? true : false;
        }
        
        /* Returns the color of the piece at the given positon
         *
         * @param x The X position
         * @param y The Y position
         */
        const Team* getTeamAt(int x, int y) const
        {
            if (isPositionLegal(x, y))
                return getPiece(x, y).getTeam();
        }
        
        /* Checks if there is line of sight (IE no pieces) between the two positions. Only works for straight lines
         *
         * @param oldX The first X position
         * @param oldY The first Y position
         * @param newX The second X position
         * @param newY The second Y position
         */
        bool lineOfSight(int oldX, int oldY, int newX, int newY) const;
		
    };
}

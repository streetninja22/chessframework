#include <cstdlib> //needed for abs() on some compilers

#include "Piece.h"
#include "PieceTypes.h"
#include "Board.h"



namespace chess
{
    bool Piece::isNoAllyAt(const Board& board, int posX, int posY) const
    {
        if (isAlly(board.getPiece(posX, posY)))
            return false;
        return true;
    }
    
    bool Pawn::isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
    {
        int deltaX = xNew - xOrigin;
        int deltaY = yNew - yOrigin;
        
        if (deltaX == 1 || deltaX == -1)
        {
            if (deltaY == 1)
            {
                if (isNoAllyAt(board, xNew, yNew))
                    return true;
            }
        }
        else if (deltaX == 0)
        {
            if (deltaY == 1)
            {
                if (!(board.isLivingPieceAt(xNew, yNew)))
				{
					return true;
				}
			}
			else if (deltaY == 2 && m_hasMoved == false)
				if (!(board.isLivingPieceAt(xOrigin, yOrigin + 1)))
					return true;
		}
					return false;
	}
                        
                        
	bool Rook::isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
	{
		int deltaX = xNew - xOrigin;
		int deltaY = yNew - yOrigin;
		
		//this basically acts as an XOR operator, so if you're moving in one axis you can't move on the other
		if (!deltaX != !deltaY)
			if (board.lineOfSight(xOrigin, yOrigin, xNew, yNew))
				return true;
		return false;
	}
	
	bool Knight::isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
	{
		int deltaX = xNew - xOrigin;
		int deltaY = yNew - yOrigin;
		
		if (!isAlly(board.getPiece(xNew, yNew)))
		{
			if (std::abs(deltaX) == 2 && std::abs(deltaY) == 1)
				return true;
			else if (std::abs(deltaX) == 1 && std::abs(deltaY) == 2)
				return true;
			return false;
		}
	}
	
	bool Bishop::isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
	{
		int deltaX = xNew - xOrigin;
		int deltaY = yNew - yOrigin;
		
		if (!isAlly(board.getPiece(xNew, yNew)))
		{
			if (deltaX == deltaY)
				if (board.lineOfSight(xOrigin, yOrigin, xNew, yNew))
					return true;
			return false;
		}
	}
	
	bool King::isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
	{
		if (std::abs(xNew - xOrigin) <= 1 && std::abs(yNew - yOrigin) <= 1)
			return true;
		
	}
	
	bool Queen::isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
	{
		int deltaX = xNew - xOrigin;
		int deltaY = yNew - yOrigin;
		
		if (deltaX == deltaY)
		{
			if (board.lineOfSight(xOrigin, yOrigin, xNew, yNew))
				return true;
		}
		if (!deltaX != !deltaY)
		{
			if (board.lineOfSight(xOrigin, yOrigin, xNew, yNew))
				return true;
		}
	}
	
}


#include "Piece.h"
#include "Board.h"


namespace chess
{

	bool Pawn::isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
	{
		int deltaX = xNew - xOrigin;
		int deltaY = yNew - yOrigin;

		if (deltaX == 1 || deltaX == -1)
		{
			if (deltaY == 1)
			{
				if (board.isLivingPieceAt(xNew, yNew))
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
				if (board.isLivingPieceAt(xOrigin, yOrigin + 1))
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

		if (abs(deltaX) == 2 && abs(deltaY) == 1)
			return true;
		else if (abs(deltaX) == 1 && abs(deltaY) == 2)
			return true;
		return false;
	}

	bool Bishop::isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
	{
		int deltaX = xNew - xOrigin;
		int deltaY = yNew - yOrigin;

		if (deltaX == deltaY)
			if (board.lineOfSight(xOrigin, yOrigin, xNew, yNew))
				return true;
		return false;
	}

	bool King::isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
	{
		if (abs(xNew - xOrigin) <= 1 && abs(yNew - yOrigin) <= 1)
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

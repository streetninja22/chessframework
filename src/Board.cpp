#include "Board.h"



bool Board::lineOfSight(int oldX, int oldY, int newX, int newY)
{
	int deltaX = newX - oldX;
	int deltaY = newY - oldY;

	//normalize values to -1, 0, or 1
	int dirX = (deltaX > 0 ? 1 : (deltaX < 0 ? -1 : 0));
	int dirY = (deltaY > 0 ? 1 : (deltaY < 0 ? -1 : 0));


	if (deltaX == deltaY)
	{
		for (int indexX = oldX; indexX < newX && indexX < m_xSize && indexX >= 0; indexX += dirX)
		{
			for (int indexY = oldY; indexY < newX && indexY < m_ySize && indexY >= 0; indexY += dirY)
			{
				if (isLivingPieceAt(indexX, indexY))
					return false;
			}
		}
		return true;
	}

	//This acts as an XOR, so if one is a value other than 0 the other must be 0 for it to return true
	if (!deltaX != !deltaY)
	{
		for (int indexX = oldX; ((deltaX == 0 && deltaY != 0) || deltaX != 0 && indexX < newX) && indexX < m_xSize && indexX >= 0; indexX += dirX) //as long as either Y changes and X doesn't, or the index is less than the new X, and index is less than the board size but greater than 0
		{
			for (int indexY = oldX; ((deltaY == 0 && deltaX != 0) || deltaY != 0 && indexY < newY) && indexY < m_ySize && indexY >= 0; indexY += dirY)
			{
				if (isLivingPieceAt(indexX, indexY))
					return false;
			}
		}
		return true;
	}

	return false;
}
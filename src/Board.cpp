#include "Board.h"

namespace chess
{

	void Board::movePiece(int xOrigin, int yOrigin, int xNew, int yNew)
	{
		getPiece(xNew, yNew) = getPiece(xOrigin, yOrigin);
		getPiece(xOrigin, yOrigin) = Piece();
	}

	bool Board::lineOfSight(int oldX, int oldY, int newX, int newY) const
	{
		int deltaX = newX - oldX;
		int deltaY = newY - oldY;

		//normalize values to -1, 0, or 1
		int dirX = (deltaX > 0 ? 1 : (deltaX < 0 ? -1 : 0));
		int dirY = (deltaY > 0 ? 1 : (deltaY < 0 ? -1 : 0));


		if (deltaX == deltaY)
		{
			for (int index = oldX; index != newX && index != m_xSize && index >= 0; index += dirX)
			{
				if (isLivingPieceAt(index, index))
					return false;
			}
			return true;
		}

		//This acts as an XOR, so if one is a value other than 0 the other must be 0 for it to return true
		if (!deltaX != !deltaY)
		{
			for (int indexX = oldX; ((deltaX == 0 && deltaY != 0) || deltaX != 0 && indexX != newX) && indexX < m_xSize && indexX >= 0; indexX += dirX) //as long as either Y changes and X doesn't, or the index is less than the new X, and index is less than the board size but greater than 0
			{
				for (int indexY = oldY; ((deltaY == 0 && deltaX != 0) || deltaY != 0 && indexY != newY) && indexY < m_ySize && indexY >= 0; indexY += dirY) //same as above, except X and Y switched
				{
					if (isLivingPieceAt(indexX, indexY))
						return false;
					if (indexY == 0 && deltaX != 0) //this can be improved in some way without needing separate loops for different cases. can probably reduce the amount of repeated code
						break;
				}
				if (indexX == 0 && deltaY != 0)
					break;
			}
			return true;
		}

		return false;
	}

}
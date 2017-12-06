#include "Board.h"
#include "PieceTypes.h"

namespace chess
{
	Board::Board(unsigned int xSize, unsigned int ySize) : m_xSize(xSize), m_ySize(ySize)
    {
		m_board.resize(xSize);
		
		for (int index = 0; index < xSize; ++index)
		{
			m_board.at(index).resize(ySize);
		}
    }
	
	Board::Board(Team* white, Team* black) : Board(8, 8)
	{
		for (int index = 0; index < m_xSize; ++index)
		{
			getPiece(index, 1) = Pawn(white);
			getPiece(index, m_xSize - 2) = Pawn(black);
		}
		
		setPiece(0, 0, Rook(white));
		setPiece(7, 0, Rook(white));
		
		setPiece(0, 7, Rook(black));
		setPiece(7, 7, Rook(black));
		
		setPiece(1, 0, Knight(white));
		setPiece(6, 0, Knight(white));
		
		setPiece(1, 7, Knight(black));
		setPiece(6, 7, Knight(black));
		
		setPiece(2, 0, Bishop(white));
		setPiece(5, 0, Bishop(white));
		
		setPiece(2, 7, Bishop(black));
		setPiece(5, 7, Bishop(black));
		
		setPiece(3, 0, Queen(white));
		setPiece(3, 7, Queen(black));
		
		setPiece(4, 0, King(white));
		setPiece(4, 7, King(black));
	}

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

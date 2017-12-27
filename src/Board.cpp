#include "Board.h"
#include "PieceTypes.h"

namespace chess
{
    void Board::resize(int xSize, int ySize)
    {
        m_board.resize(xSize);
        for (int indexX = 0; indexX < xSize; ++indexX)
        {
            m_board.at(indexX).resize(ySize);
        }
    }
	
	void Board::initializeBoard()
	{
		for (int indexX = 0; indexX < xSize(); ++indexX)
		{
			for (int indexY = 0; indexY < ySize(); ++indexY)
			{
				setPiece(indexX, indexY, new Piece());
			}
		}
	}
    
	Board::Board(unsigned int xSize, unsigned int ySize) : m_xSize(xSize), m_ySize(ySize)
    {
        resize(xSize, ySize);
		initializeBoard();
    }
	
	Board::Board(Team* white, Team* black) : Board(8, 8)
	{
		for (int index = 0; index < m_xSize; ++index)
		{
			setPiece(index, 1, new Pawn(white, true));
			setPiece(index, m_xSize - 2, new Pawn(black, false));
		}
		
		setPiece(0, 0, new Rook(white));
		setPiece(7, 0, new Rook(white));
		
		setPiece(0, 7, new Rook(black));
		setPiece(7, 7, new Rook(black));
		
		setPiece(1, 0, new Knight(white));
		setPiece(6, 0, new Knight(white));
		
		setPiece(1, 7, new Knight(black));
		setPiece(6, 7, new Knight(black));
		
		setPiece(2, 0, new Bishop(white));
		setPiece(5, 0, new Bishop(white));
		
		setPiece(2, 7, new Bishop(black));
		setPiece(5, 7, new Bishop(black));
		
		setPiece(3, 0, new Queen(white));
		setPiece(3, 7, new Queen(black));
		
		setPiece(4, 0, new King(white));
		setPiece(4, 7, new King(black));

	}

	void Board::movePiece(int xOrigin, int yOrigin, int xNew, int yNew)
	{
        if (isPositionLegal(xOrigin, yOrigin) && isPositionLegal(xNew, yNew))
        {
			delete getPointer(xNew, yNew);
			getPointerReference(xNew, yNew) = getPointer(xOrigin, yOrigin);
			getPointerReference(xOrigin, yOrigin) = new Piece();
        }
	}

	bool Board::lineOfSight(int oldX, int oldY, int newX, int newY) const
	{
		if (!(isPositionLegal(oldX, oldY) && isPositionLegal(newX, newY)))
        {
            return false;
        }
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
    
    bool Board::isMoveLegal(int xOrigin, int yOrigin, int xNew, int yNew)
    {
        return getPointer(xOrigin, yOrigin)->isMoveLegal(*this, xOrigin, yOrigin, xNew, yNew);
    }

}

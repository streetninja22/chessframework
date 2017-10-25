#include "Piece.h"
#include "Board.h"

bool Pawn::isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
{
	int deltaX = xNew - xOrigin;
	int deltaY = yNew - yOrigin;

	switch (deltaX)
	{
	case 1:
	case -1:
		if (deltaY == 1)
		{
			if (board.isLivingPieceAt(xNew, yNew))
				return true;
		}
		break;

	case 0:
		if (deltaY == 1 || (deltaY == 2 && !m_hasMoved))
			if (!(board.isLivingPieceAt(xNew, yNew)))
				return true;
		break;
	}
	return false;
}


bool Rook::isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
{
	int deltaX = xNew - xOrigin;
	int deltaY = yNew - yOrigin;

	//this basically acts as an XOR operator, so if you're moving in one axis you can't move on the other
	if (!deltaX != !deltaY)
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
		return true;
	return false;
}


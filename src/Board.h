#pragma once
#include <array>
#include "Piece.h"


class Board
{
	std::array<std::array<Piece, 8>, 8> m_board;
	int m_xSize;
	int m_ySize;

public:
	Board() : m_xSize(8), m_ySize(8)
	{

	}
	~Board()
	{

	}

	int xSize() const { return m_xSize; }
	int ySize() const { return m_ySize; }

	Piece& getPiece(int x, int y)
	{
		return m_board.at(x).at(y);
	}

	const Piece& getPiece(int x, int y) const
	{
		return m_board.at(x).at(y);
	}

	PieceColor isLivingPieceAt(int x, int y) const
	{
		if (x < m_xSize && y < m_ySize)
			return getPiece(x, y).getColor();
	}
};
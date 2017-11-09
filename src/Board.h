#pragma once
#include <array>
#include "Piece.h"

namespace chess
{

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

		/* Returns the piece at the given position
		*
		* @param x The X position
		* @param y The Y position
		*/
		Piece& getPiece(int x, int y)
		{
			if (x < m_xSize && y < m_ySize)
				return m_board.at(x).at(y);
		}

		/* Returns the piece at the given position
		*
		* @param x The X position
		* @param y The Y position
		*/
		const Piece& getPiece(int x, int y) const
		{
			if (x < m_xSize && y < m_ySize)
				return m_board.at(x).at(y);
		}

		/* Sets the position to the given piece
		*
		* @param x The X position to set
		* @param y The Y position to set
		* @param piece The piece to copy
		*/
		void setPiece(int x, int y, Piece piece)
		{
			if (x < m_xSize && y < m_ySize)
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
			if (x < m_xSize && y < m_ySize)
                return getPiece(x, y).getTeam() != nullptr ? true : false;
		}

		/* Returns the color of the piece at the given positon
		*
		* @param x The X position
		* @param y The Y position
		*/
		const Team* getTeamAt(int x, int y) const
		{
			if (x < m_xSize && y < m_ySize)
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

#pragma once
#include "Team.h"

class Board;

namespace chess
{

	enum class PieceType
	{
		NONE,
		PAWN,
		ROOK,
		KNIGHT,
		BISHOP,
		KING,
		QUEEN
	};


	class Piece
	{
	protected:
		PieceType m_type;
		Team* m_team;


		Piece(PieceType type, Team* team) : m_type(type), m_team(team)
		{

		}
	public:
		Piece() : m_type(PieceType::NONE), m_team(nullptr)
		{
		}

		PieceType getType() const { return m_type; }

		const Team* getTeam() const { return m_team; }

		virtual bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
		{
			return false;
		}

	};


	class Pawn : public Piece
	{
		bool m_hasMoved;

	public:
		Pawn(Team* team) : m_hasMoved(false), Piece(PieceType::PAWN, team)
		{
		}

		bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;

	};

	class Rook : public Piece
	{
	public:
		Rook(Team* team) : Piece(PieceType::ROOK, team)
		{
		}

		bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;
	};

	class Knight : public Piece
	{
	public:
		Knight(Team* team) : Piece(PieceType::KNIGHT, team)
		{
		}

		bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;
	};

	class Bishop : public Piece
	{
	public:
		Bishop(Team* team) : Piece(PieceType::BISHOP, team)
		{
		}

		bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;
	};

	class King : public Piece
	{
	public:
		King(Team* team) : Piece(PieceType::KING, team)
		{
		}

		bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;
	};

	class Queen : public Piece
	{
	public:
		Queen(Team* team) : Piece(PieceType::KING, team)
		{
		}

		bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;
	};

}
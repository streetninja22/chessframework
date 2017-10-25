#pragma once

class Board;

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

enum class PieceColor
{
	NONE,
	WHITE,
	BLACK,
};


class Piece
{
protected:
	PieceType m_type;
	PieceColor m_color;


	Piece(PieceType type, PieceColor color) : m_type(type), m_color(color)
	{

	}
public:
	Piece() : m_type(PieceType::NONE), m_color(PieceColor::NONE)
	{
	}

	PieceType getType() const { return m_type; }

	PieceColor getColor() const { return m_color; }

	virtual bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew)
	{
		return false;
	}

};


class Pawn : public Piece
{
	bool m_hasMoved;

public:
	Pawn(PieceColor color) : m_hasMoved(false), Piece(PieceType::PAWN, color)
	{
	}

	bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;

};

class Rook : public Piece
{
public:
	Rook(PieceColor color) : Piece(PieceType::ROOK, color)
	{
	}

	bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;
};

class Knight : public Piece
{
public:
	Knight(PieceColor color) : Piece(PieceType::KNIGHT, color)
	{
	}

	bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;
};

class Bishop : public Piece
{
public:
	Bishop(PieceColor color) : Piece(PieceType::BISHOP, color)
	{
	}

	bool isMoveLegal(const Board& board, int xOrigin, int yOrigin, int xNew, int yNew) override;
};

class King : public Piece
{

};
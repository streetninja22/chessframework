#include "ChessGraphics.h"

using namespace gfx;

namespace chess
{
	
	Color ChessGraphics::getTileColorAt(int x, int y)
	{
		if (y % 2)
		{
			if (x % 2)
				return TILE_WHITE_COLOR;
			else
				return TILE_BLACK_COLOR;
		}
		if (x % 2)
			return TILE_BLACK_COLOR;
		else
			return TILE_WHITE_COLOR;
	}
	
	void ChessGraphics::drawTiles(GraphicsSystem* graphics, Rect area)
	{
		int boardSizeX = m_game->getBoard().xSize();
		int boardSizeY = m_game->getBoard().ySize();
		
		for (int indexX = 0; indexX < boardSizeX; ++indexX)
		{
			for (int indexY = 0; indexY < boardSizeY; ++indexY)
			{
				Rect* tile = new Rect();
				tile->x = tileWidth() * indexX + area.x;
				tile->y = tileHeight() * indexY + area.y;
				tile->w = tileWidth();
				tile->h = tileHeight();
				
				graphics->renderFillRect(tile, getTileColorAt(indexX + 1, indexY + 1)); //add 1 to getTileColorAt coordinates because it assumes it starts at 1 rather than 0
			}
		}
	}
	
	Rect ChessGraphics::getPieceSpriteRect(PieceType piece)
	{
		int posX;
		int posY;
		
		switch(piece)
		{
			default:
			case (PieceType::PAWN):
			{
				posX = 0;
				posY = 0;
				break;
			}
			case (PieceType::ROOK):
			{
				posX = SPRITE_SIZE_PIXELS;
				posY = 0;
				break;
			}
			case (PieceType::KNIGHT):
			{
				posX = 2*SPRITE_SIZE_PIXELS;
				posY = 0;
				break;
			}
			case (PieceType::BISHOP):
			{
				posX = 0;
				posY = SPRITE_SIZE_PIXELS;
				break;
			}
			case (PieceType::QUEEN):
			{
				posX = SPRITE_SIZE_PIXELS;
				posY = SPRITE_SIZE_PIXELS;
				break;
			}
			case (PieceType::KING):
			{
				posX = 2*SPRITE_SIZE_PIXELS;
				posY = SPRITE_SIZE_PIXELS;
				break;
			}
		}
		
		return {posX, posY, SPRITE_SIZE_PIXELS, SPRITE_SIZE_PIXELS};
	}
	
	void ChessGraphics::drawSprites(GraphicsSystem* graphics)
	{
		int boardSizeX = m_game->getBoard().xSize();
		int boardSizeY = m_game->getBoard().ySize();
		for (int xIndex = 0; xIndex < boardSizeX; ++xIndex)
		{
			for (int yIndex = 0; yIndex < boardSizeY; ++yIndex)
			{
				Piece piece = m_game->getBoard().getPiece(xIndex, yIndex);
				
				Rect sourceRect = getPieceSpriteRect(piece.getType());
				
				Rect destRect = {tileWidth()*xIndex, tileHeight()*yIndex, tileWidth(), tileHeight()};
				
				graphics->renderTexture(*m_spriteSheet, &sourceRect, &destRect);
			}
		}
	}
	
	void ChessGraphics::drawBoard(GraphicsSystem* graphics)
	{
		if (m_spriteSheet == nullptr)
		{
			loadSpriteSheet(graphics);
		}
		
		graphics->renderTexture(*m_spriteSheet, NULL, NULL);
		
		//drawTiles(graphics, m_boardSize);
		//drawSprites(graphics);
	}
	
	
	void ChessGraphics::update(GraphicsSystem* graphics)
	{
		drawBoard(graphics);
	}
	
}

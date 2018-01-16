#pragma once

#include "Chess.h"
#include "GraphicsSystem.h"
#include "GraphicsEvents.h"
#include "InputSystem.h"
#include "System.h"
#include "assets.h"

using namespace gfx;


const std::string SPRITE_SHEET_PATH = file::getMainDirectoryFileStr("gfx/sprites.png");
const Color TILE_WHITE_COLOR = {255, 255, 255, 0};
const Color TILE_BLACK_COLOR = {50, 50, 50, 0};
const int SPRITE_SIZE_PIXELS = 16;


namespace chess
{

	class ChessGraphics : public System
	{
		ChessGame* m_game;
		Rect m_boardSize;
		Texture* m_spriteSheet;
		
		
	public:
		ChessGraphics(EventBus* bus, ChessGame* game, Rect boardDimensions) : System(bus), m_game(game), m_boardSize(boardDimensions)
		{
			
		}
		
		~ChessGraphics()
		{
			
		}
		
		void loadSpriteSheet(GraphicsSystem* graphics)
		{
			m_spriteSheet = graphics->loadTexture(SPRITE_SHEET_PATH);
			
		}
		
		Color getTileColorAt(int x, int y);
		
		
		/* Gets the source rect for a piece on the chess sprite sheet
		 *
		 * @param piece The PieceType for the piece
		 */
		Rect getPieceSpriteRect(PieceType piece);
		
		void drawTiles(GraphicsSystem* graphics, Rect area);
		
		void drawSprites(GraphicsSystem* graphics);
		
		void drawBoard(GraphicsSystem* graphics);
		
		void update(GraphicsSystem* graphics);
		
		int tileWidth() { return m_boardSize.w / m_game->getBoard().xSize(); }
		
		int tileHeight() { return m_boardSize.h / m_game->getBoard().ySize(); }
		
	};
}

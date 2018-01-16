#include <iostream>
#include "Event.h"
#include "InputSystem.h"
#include "GraphicsSystem.h"
#include "assets.h"
#include "Piece.h"
#include "Board.h"
#include "includeSDL.h"
#include "commandline.h"
#include "ChessGraphics.h"

const int WINDOW_SIZE_X = 480;
const int WINDOW_SIZE_Y = 480;

int main(int argc, char* argv[])
{
    std::cout << "Initializing chess\n";
    
    evnt::EventBus* bus = new EventBus();
	
	GraphicsSystem graphics(bus, "Chess", 0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y);
    
    chess::ChessGame game(bus);
	
	chess::ChessGraphics chessGraphics(bus, &game, {0, 0, 480, 480});
	
    while (true)
    {
		bus->callListeners();
		
		chessGraphics.update(&graphics);
		
		graphics.update();
    }
    
	return 0;
}

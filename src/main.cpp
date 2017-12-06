#include <iostream>
#include "Event.h"
#include "InputSystem.h"
#include "GraphicsSystem.h"
#include "assets.h"
#include "Piece.h"
#include "Board.h"
#include "includeSDL.h"
#include "commandline.h"

int main(int argc, char* argv[])
{
    std::cout << "Initializing chess\n";
    
    evnt::EventBus* bus = new EventBus();
    
    chess::ChessGame game(bus);
	
    while (true)
    {
        chess::takeChessCommandInput(game);
    }
    
	return 0;
}

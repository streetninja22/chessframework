#include <iostream>
#include "includeSDL.h"
#include "Event.h"
#include "InputSystem.h"
#include "GraphicsSystem.h"
#include "assets.h"
#include "Piece.h"
#include "Board.h"

int main(int argc, char* argv[])
{
	Board board = Board();

	board.setPiece(4, 4, Pawn(COLOR_WHITE));

	std::cout << board.lineOfSight(0, 0, 0, 5) << "\n";
	std::cout << board.lineOfSight(0, 0, 5, 0) << "\n";
	std::cout << board.lineOfSight(0, 0, 5, 5) << "\n";
	std::cout << board.lineOfSight(0, 5, 0, 0) << "\n";
	std::cout << board.lineOfSight(5, 0, 0, 0) << "\n";
	std::cout << board.lineOfSight(5, 5, 0, 0) << "\n";

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return 0;
}

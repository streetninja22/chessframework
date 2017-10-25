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
	Pawn piece = Pawn();
	Board board = Board();

	std::cout << piece.isMoveLegal(board, 0, 0, 0, 1) << " " << piece.isMoveLegal(board, 0, 0, 1, 0) << " " << piece.isMoveLegal(board, 0, 0, 1, 1) << "\n";

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return 0;
}

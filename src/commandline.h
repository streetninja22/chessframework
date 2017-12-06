#pragma once
#include <iostream>
#include <string>
#include "Board.h"

std::string tolower(std::string string)
{
	std::string newString = string;
	
	for (char& index : newString)
	{
		index = tolower(index);
	}
	return newString;
}

int takeIntInput()
{
    int input;
    
    while (true)
    {
        std::cin >> input;
        
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
            std::cout << "Error with argument input\n";
        }
		else
			return input;
    }
}

std::string takeStringInput()
{
	std::string input;
	std::cin >> input;
	
	input = tolower(input.c_str());
	return input;
}


namespace chess
{
    
	char pieceTypeToChar(PieceType type)
	{
        switch(type)
        {
            case PieceType::PAWN:
                return 'P';
            case PieceType::ROOK:
                return 'R';
            case PieceType::KNIGHT:
                return 'N';
            case PieceType::BISHOP:
                return 'B';
            case PieceType::QUEEN:
                return 'Q';
            case PieceType::KING:
                return 'K';
            default:
                return '+';
        }
    }
    
	
	void outputBoard(const Board &board, std::ostream& output)
	{
		for (int indexY = 0; indexY < board.ySize(); ++indexY)
		{
			for (int indexX = 0; indexX < board.xSize(); ++indexX)
			{
				output << pieceTypeToChar(board.getPiece(indexX, indexY).getType());
			}
			output << '\n';
		}
	}
	
	void takeChessCommandInput(ChessGame &game)
	{
		std::string command = takeStringInput();
		
		if (command == "run")
		{
			game.update();
			outputBoard(game.getBoard(), std::cout);
		}
		else if(command == "setpiece")
		{
			int x = takeIntInput();
			int y = takeIntInput();
			
			game.addGameEvent({ChessGameEventType::SET_SELECTION, {static_cast<unsigned int>(x), static_cast<unsigned int>(y)}});
		}
		else if(command == "movepiece")
		{
			int x = takeIntInput();
			int y = takeIntInput();
			
			game.addGameEvent({ChessGameEventType::MOVE_PIECE, {static_cast<unsigned int>(x), static_cast<unsigned int>(y)}});
		}
	}
}

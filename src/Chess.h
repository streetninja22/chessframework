#pragma once
#include "Piece.h"
#include "Board.h"
#include <queue>
#include "Event.h"


struct Pos
{
	unsigned int x;
	unsigned int y;
};

namespace chess
{
	enum class ChessGameEventType
	{
		SET_SELECTION,
		MOVE_PIECE,
	};

	struct ChessGameEvent
	{
		ChessGameEventType type;
		Pos position;
	};

	class ChessGame : public evnt::EventNode
	{
		Board m_board;
		Pos selectionPos; //the position of the selection
		bool selected; //whether anything is selected in the first place

		std::queue<ChessGameEvent> inputEventQueue; //event queue, not to be confused with an actual event bus queue


		void eventFired(evnt::Event* event)
		{
			using namespace evnt;


		}

	public:

		void update()
		{

		}

	};

}
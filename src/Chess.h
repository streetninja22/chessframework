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

	class ChessGame
	{
		Board* m_board;
		Pos m_selectionPos; //the position of the selection
		bool m_selected; //whether anything is selected in the first place
		
		Team* m_currentTeam;
        Team m_white;
        Team m_black;

		std::queue<ChessGameEvent> m_inputEventQueue; //event queue, not to be confused with an actual event bus queue


		void eventFired(evnt::Event* event)
		{
			using namespace evnt;


		}

	public:
        ChessGame(evnt::EventBus* bus);

        void update();
        
		const Board& getBoard() const
        {
            return *m_board;
        }
        
        void addGameEvent(ChessGameEvent event)
        {
            m_inputEventQueue.push(event);
        }
        
        void interpretEvent(ChessGameEvent event);
		
		bool movePiece(Pos origin, Pos dest);
		
		void endTurn();
		
		std::string getCurrentTeamName()
		{
			if (m_currentTeam != nullptr)
				return m_currentTeam->getName();
			return "No team";
		}
		
		bool isSelection() { return m_selected; }

	};

}

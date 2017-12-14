#include "Chess.h"
#include <iostream>

namespace chess
{

    ChessGame::ChessGame(evnt::EventBus* bus) : m_white("White"), m_black("Black"), m_board(new Board(&m_white, &m_black)), m_selected(false), evnt::EventNode(bus)
    {
    }
	
	void ChessGame::movePiece(Pos origin, Pos dest)
	{
		if (m_board->getPiece(origin.x, origin.y).isMoveLegal(*m_board, origin.x, origin.y, dest.x, dest.y))
		{
			m_board->movePiece(origin.x, origin.y, dest.x, dest.y);
		}
	}
	
    void ChessGame::interpretEvent(ChessGameEvent event)
    {
        switch(event.type)
        {
            case (ChessGameEventType::SET_SELECTION):
				if (m_board->isPositionLegal(event.position.x, event.position.y))
				{
					m_selected = true;
					m_selectionPos = event.position;
				}
                break;
            case (ChessGameEventType::MOVE_PIECE):
				if (m_selected)
					movePiece(m_selectionPos, event.position);
                break;
        }
    }

    
    void ChessGame::update()
    {
        while (m_inputEventQueue.size() >= 1)
        {
            interpretEvent(m_inputEventQueue.front());
            m_inputEventQueue.pop();
        }
        
    }
}

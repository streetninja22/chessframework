#include "Chess.h"
#include <iostream>

namespace chess
{

    ChessGame::ChessGame(evnt::EventBus* bus) : m_white("White"), m_black("Black"), m_currentTeam(&m_white), m_board(new Board(&m_white, &m_black)), m_selected(false)
    {
    }
	
	bool ChessGame::movePiece(Pos origin, Pos dest)
	{
		if (m_board->isMoveLegal(origin.x, origin.y, dest.x, dest.y))
		{
			m_board->movePiece(origin.x, origin.y, dest.x, dest.y);
			return true;
		}
		return false;
	}
	
	void ChessGame::endTurn()
	{
		m_selected = false;
		if (m_currentTeam == &m_white)
			m_currentTeam = &m_black;
		else
			m_currentTeam = &m_white;
	}
	
    void ChessGame::interpretEvent(ChessGameEvent event)
    {
        switch(event.type)
        {
            case (ChessGameEventType::SET_SELECTION):
				if (m_board->isPositionLegal(event.position.x, event.position.y))
				{
					Piece* piece = &m_board->getPiece(event.position.x, event.position.y);
					if (piece->isNotBlank() && piece->getTeam() == m_currentTeam)
					{
						m_selected = true;
						m_selectionPos = event.position;
					}
					m_selected = false;
				}
                break;
            case (ChessGameEventType::MOVE_PIECE):
				if (m_selected)
				{
					if  (movePiece(m_selectionPos, event.position))
						endTurn();
				}
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

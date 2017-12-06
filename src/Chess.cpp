#include "Chess.h"

namespace chess
{

    ChessGame::ChessGame(evnt::EventBus* bus) : m_white("White"), m_black("Black"), m_board(new Board(&m_white, &m_black)), m_selected(false), evnt::EventNode(bus)
    {
    }

    
    void ChessGame::update()
    {
        
    }
}

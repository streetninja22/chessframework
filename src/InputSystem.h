#pragma once

#include "System.h"
#include "Event.h"
#include "Keycode.h"
#include "includeSDL.h"

namespace inpt
{

	enum KeyEventType
	{
		KEYDOWN,
		KEYUP
	};

	enum MouseEventType
	{
		MOUSEMOTION,
		LEFTMOUSEDOWN,
		RIGHTMOUSEDOWN,
		MIDDLEMOUSEDOWN,
		LEFTMOUSEUP,
		RIGHTMOUSEUP,
		MIDDLEMOUSEUP
	};

	class KeyboardEvent : public Event
	{
		KeyEventType m_type;
		KeyCode m_keyCode;

	public:
		KeyboardEvent(KeyEventType type, KeyCode keyCode) : m_type(type), m_keyCode(keyCode)
		{
		}

		KeyEventType getType()
		{
			return m_type;
		}

		KeyCode getKeyCode()
		{
			return m_keyCode;
		}
	};


	class MouseEvent : public Event
	{
		int m_posX;
		int m_posY;

		MouseEventType m_type;

	public:
		MouseEvent(int posX, int posY, MouseEventType type) : m_posX(posX), m_posY(posY), m_type(type)
		{

		}
        
        /* Returns the X coordinate of the mouse
        */
		int getX()
		{
			return m_posX;
		}
        
        /* Returns the Y coordinate of the mouse
         */
		int getY()
		{
			return m_posY;
		}
        
        /* Returns the type of mouse input (left click, right click, mmb, etc)
         */
		MouseEventType getType()
		{
			return m_type;
		}
        
        /* Sets the type of mouse input
         * @param type The type
         */
		void setType(MouseEventType type)
		{
			m_type = type;
		}
	};

	class InputSystem : public System
	{


	public:
		InputSystem(EventBus* bus) : System(bus)
		{

		}

		void updateInput();

	};

	//TODO finish input system
}

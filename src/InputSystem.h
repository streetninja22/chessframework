#pragma once

#include <SDL.h>
#include "System.h"
#include "Event.h"
#include "Keycode.h"

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

		int getX()
		{
			return m_posX;
		}

		int getY()
		{
			return m_posY;
		}

		MouseEventType getType()
		{
			return m_type;
		}

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

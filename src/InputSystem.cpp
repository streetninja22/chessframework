#include "InputSystem.h"
#include "Keycode.h"


namespace inpt
{

	void InputSystem::updateInput()
	{
		//TODO break this function down
		SDL_Event inputEvent;

		while (SDL_PollEvent(&inputEvent))
		{
			switch (inputEvent.type)
			{
				//To avoid reusing code, we're going to initialize the output event first then set the type values within the case statements and then add it to the event queue outside of the switch
			case (SDL_MOUSEBUTTONDOWN):
			{
				//MOUSEBUTTONDOWN start
				MouseEvent* outputEvent{ new MouseEvent(inputEvent.button.x, inputEvent.button.y, MouseEventType::LEFTMOUSEDOWN) };

				switch (inputEvent.button.button)
				{
				case (SDL_BUTTON_RIGHT):
					outputEvent->setType(MouseEventType::RIGHTMOUSEDOWN);
					break;

				case (SDL_BUTTON_MIDDLE):
					outputEvent->setType(MouseEventType::MIDDLEMOUSEDOWN);
					break;
				}

				addEvent(outputEvent);
				break;
			}

			//MOUSEBUTTONDOWN end

			case (SDL_MOUSEBUTTONUP):
			{
				MouseEvent* outputEvent{ new MouseEvent(inputEvent.button.x, inputEvent.button.y, MouseEventType::LEFTMOUSEUP) };

				switch (inputEvent.button.button)
				{
				case (SDL_BUTTON_RIGHT):
					outputEvent->setType(MouseEventType::RIGHTMOUSEUP);
					break;

				case (SDL_BUTTON_MIDDLE):
					outputEvent->setType(MouseEventType::MIDDLEMOUSEUP);
					break;
				}
				addEvent(outputEvent);
				break;
				//MOUSEBUTTONUP end
			}

			case (SDL_MOUSEMOTION):
			{
				MouseEvent* outputEvent{ new MouseEvent(inputEvent.button.x, inputEvent.button.y, MouseEventType::MOUSEMOTION) };
				addEvent(outputEvent);
				break;
				//MOUSEMOTION end
			}

			//TODO add any other types of input here before keyboard events


			case (SDL_KEYDOWN):
			{
				KeyCode code = scancodeToKeycode(inputEvent.key.keysym.scancode);
				KeyboardEvent* outputEvent{ new KeyboardEvent(KeyEventType::KEYDOWN, code) };

				addEvent(outputEvent);
				break;
				//KEYDOWN end
			}

			case (SDL_KEYUP):
			{
				KeyCode code = scancodeToKeycode(inputEvent.key.keysym.scancode);
				KeyboardEvent* outputEvent{ new KeyboardEvent(KeyEventType::KEYUP, code) };

				addEvent(outputEvent);
				break;
				//KEYUP end
			}

			//TODO finish updateInput function
			}
		}
	}
}
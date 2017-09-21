#include <iostream>
#include "includeSDL.h"
#include "Event.h"
#include "InputSystem.h"
#include "GraphicsSystem.h"

void printEvent(Event* event)
{
	if (dynamic_cast<inpt::KeyboardEvent*>(event))
	{
		std::cout << dynamic_cast<inpt::KeyboardEvent*>(event)->getKeyCode() << " " << dynamic_cast<inpt::KeyboardEvent*>(event)->getType() << '\n';
	}
	if (dynamic_cast<inpt::MouseEvent*>(event))
	{
		std::cout << dynamic_cast<inpt::MouseEvent*>(event)->getType() << " " << dynamic_cast<inpt::MouseEvent*>(event)->getX() << ", " << dynamic_cast<inpt::MouseEvent*>(event)->getY() << '\n';
	}
}


int main(int argc, char* argv[])
{
	using namespace gfx;

	evnt::EventBus* bus = new evnt::EventBus();

	GraphicsSystem* graphics = new GraphicsSystem(bus, "TestWindow", 512, 512, 512, 512);

	while (true)
	{
		graphics->setDefaultRenderColor(Color{ 128, 0, 128, 255 });
		graphics->renderDrawRect(10, 10, 256, 128);
		graphics->renderFillRect(180, 50, 100, 130);
		
		graphics->setDefaultRenderColor(Color{ 255, 255, 255, 255 });
		graphics->update();
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//TODO main
	//TODO gameplay system
	//TODO sound system
	return 0;
}

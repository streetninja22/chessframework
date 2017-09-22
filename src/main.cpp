#include <iostream>
#include "includeSDL.h"
#include "Event.h"
#include "InputSystem.h"
#include "GraphicsSystem.h"
#include "assets.h"

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

	std::string file = file::getGfxFile("cryofreeze.jpg").string();

	std::cout << file << "\n";

	gfx::Texture texture = graphics->loadImage("C:\\Users\\trist\\OneDrive\\Documents\\Visual Studio 2015\\Projects\\Chess\\Chess\\gfx\\cryofreeze.jpg\\");

	while (true)
	{
		graphics->renderTexture(texture, NULL, NULL);
		
		graphics->update();
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//TODO main
	//TODO gameplay system
	//TODO sound system
	return 0;
}

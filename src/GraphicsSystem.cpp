#include "GraphicsSystem.h"
#include "SDLUtility.h"
#include "cleanup.h"

namespace gfx
{
	/* In initializing the system, also creates a window and a render for window
	*
	* @param bus The EventBus which the system will read from
	* @param name The name of the window to be created
	* @param x The X coordinate of the window on the screen
	* @param y the Y coordinate of the window on the screen
	* @param w The width of the window on the screen
	* @param h The height of the window on the screen
	*/
	GraphicsSystem::GraphicsSystem(evnt::EventBus* bus, std::string name, int x, int y, int w, int h) : System(bus)
	{
		m_window = SDL_CreateWindow(name.c_str(), x, y, w, h, SDL_WINDOW_SHOWN);
		if (m_window == nullptr)
		{
			throw new GraphicsException(1, "Failed to initialize SDL_Window");
			SDLUtil::logSDLError(std::cout, "CreateWindow");
			SDLUtil::cleanup(m_window);

		}

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
		if (m_renderer == nullptr)
		{
			throw new RenderException(2, "Failed to initialize SDL_Renderer");
			SDLUtil::logSDLError(std::cout, "CreateRenderer");
			SDLUtil::cleanup(m_renderer, m_window);

		}

	}

	GraphicsSystem::~GraphicsSystem()
	{
		SDLUtil::cleanup(m_renderer, m_window);
	}


	void GraphicsSystem::setRenderDrawColor(Color color)
	{
		SDL_SetRenderDrawColor(m_renderer, color.red, color.green, color.blue, color.alpha);
	}


	void GraphicsSystem::setDefaultRenderColor(Color color)
	{
		m_defaultRenderColor = color;
		setRenderDrawColor(color);
	}

	/* Draws an unfilled rectangle on the screen
	*
	* @param x The x coordinate of the rectangle on the window
	* @param y The Y coordinate of the rectangle on the window
	* @param w The width of the rectangle
	* @param h The height of the rectangle
	*/
	void GraphicsSystem::renderDrawRect(int x, int y, int w, int h)
	{
		setRenderDrawColor(m_defaultRenderColor);
		SDL_Rect* rect = new SDL_Rect();

		rect->x = x;
		rect->y = y;
		rect->w = w;
		rect->h = h;

		SDL_RenderDrawRect(m_renderer, rect);
	}


	/* Draws a filled rectangle on the screen
	*
	* @param x The x coordinate of the rectangle on the window
	* @param y The Y coordinate of the rectangle on the window
	* @param w The width of the rectangle
	* @param h The height of the rectangle
	*/
	void GraphicsSystem::renderFillRect(int x, int y, int w, int h)
	{
		setRenderDrawColor(m_defaultRenderColor);
		SDL_Rect* rect = new SDL_Rect();

		rect->x = x;
		rect->y = y;
		rect->w = w;
		rect->h = h;

		SDL_RenderFillRect(m_renderer, rect);
	}


	/* Draws an unfilled rectangle on the screen of the specified color
	*
	* @param x The x coordinate of the rectangle on the window
	* @param y The Y coordinate of the rectangle on the window
	* @param w The width of the rectangle
	* @param h The height of the rectangle
	*/
	void GraphicsSystem::renderDrawRect(int x, int y, int w, int h, Color color)
	{
		setRenderDrawColor(color);
		SDL_Rect* rect = new SDL_Rect();

		rect->x = x;
		rect->y = y;
		rect->w = w;
		rect->h = h;

		SDL_RenderDrawRect(m_renderer, rect);
		setRenderDrawColor(m_defaultRenderColor);
	}

	void GraphicsSystem::renderFillRect(int x, int y, int w, int h, Color color)
	{
		setRenderDrawColor(color);
		SDL_Rect* rect = new SDL_Rect();

		rect->x = x;
		rect->y = y;
		rect->w = w;
		rect->h = h;

		SDL_RenderFillRect(m_renderer, rect);
		setRenderDrawColor(m_defaultRenderColor);
	}



}
#pragma once

#include <string>
#include <SDL.h>
#include "Event.h"
#include "System.h"
#include "Exception.h"


namespace gfx {
	//TODO exceptions


	class GraphicsException : Exception
	{
	public:
		GraphicsException(int code, std::string value) : Exception(code, value)
		{

		}

	};

	class RenderException : GraphicsException
	{
	public:
		RenderException(int code, std::string value) : GraphicsException(code, value)
		{

		}

	};

	/* Stores the color value of objects to draw in RBGA
	*/
	struct Color
	{
		Uint8 red;
		Uint8 green;
		Uint8 blue;
		Uint8 alpha;
	};

	//TODO write graphics system

	class GraphicsSystem : public System
	{
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		Color m_defaultRenderColor;


		//private because we don't want the user screwing with this
		void setRenderDrawColor(Color color);

	public:
		GraphicsSystem(evnt::EventBus* bus, std::string name, int x, int y, int w, int h);

		~GraphicsSystem();

		void update()
		{
			SDL_RenderPresent(m_renderer);
			SDL_RenderClear(m_renderer);
		}


		/* Draws an unfilled rectangle on the screen
		*
		* @param x The x coordinate of the rectangle on the window
		* @param y The Y coordinate of the rectangle on the window
		* @param w The width of the rectangle
		* @param h The height of the rectangle
		*/
		void renderDrawRect(int x, int y, int w, int h);


		/* Draws a filled rectangle on the screen
		*
		* @param x The x coordinate of the rectangle on the window
		* @param y The Y coordinate of the rectangle on the window
		* @param w The width of the rectangle
		* @param h The height of the rectangle
		*/
		void renderFillRect(int x, int y, int w, int h);

		/* Draws an unfilled rectangle on the screen of the specified color
		*
		* @param x The x coordinate of the rectangle on the window
		* @param y The Y coordinate of the rectangle on the window
		* @param w The width of the rectangle
		* @param h The height of the rectangle
		* @param color The color of the rectangle
		*/
		void GraphicsSystem::renderDrawRect(int x, int y, int w, int h, Color color);


		/* Draws an filled rectangle on the screen of the specified color
		*
		* @param x The x coordinate of the rectangle on the window
		* @param y The Y coordinate of the rectangle on the window
		* @param w The width of the rectangle
		* @param h The height of the rectangle
		* @param color The color of the rectangle
		*/
		void GraphicsSystem::renderFillRect(int x, int y, int w, int h, Color color);

		/* Sets the default color to render objects
		*
		* @param color The color to set
		*/
		void setDefaultRenderColor(Color color);

	};

}
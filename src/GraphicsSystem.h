#pragma once

#include <string>
#include "includeSDL.h"
#include "Event.h"
#include "System.h"
#include "Exception.h"
#include "graphicsenum.h"
#include <experimental/filesystem>
#include <SDL_image.h>

namespace fs = std::experimental::filesystem;

namespace gfx {
	//TODO exceptions

	/* Basic graphics exception
	*
	*/
	class GraphicsException : Exception
	{
	public:
		GraphicsException(int code, std::string value) : Exception(code, value)
		{

		}

	};

	//A graphics exception which is thrown when an error involving rendering occurs
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

	struct Rect
	{
		int x;
		int y;
		int h;
		int w;

	};

	SDL_Rect* SDLRectFromRect(SDL_Rect* r1, Rect* r2);

	SDL_Rect* SDLRectFromRect(Rect* r2);

    class Texture
    {
        SDL_Texture* m_texture;


	public:
		SDL_Texture* getTexture()
		{
			return m_texture;
		}

        Texture() : m_texture(nullptr)
        {
        }

		Texture(SDL_Texture* texture) : m_texture(texture)
		{
		}

		void setTexture(SDL_Texture* texture)
		{
			m_texture = texture;
		}

		void freeTexture()
		{
			SDL_DestroyTexture(m_texture);
		}

    };



	//A basic Graphics System event
	class GraphicsEvent : public Event
	{

	public:
		GraphicsEvent()
		{

		}

		virtual EventType getEventType() { return EventType::GRAPHICS; }
		virtual GraphicsEventType getGraphicsEventType() { return GraphicsEventType::DEFAULT; }

	};

	//An event which calls for the GraphicsSystem to render an object
	class RenderEvent : public GraphicsEvent
	{
		Rect* m_dstrect;

	public:
		RenderEvent()
		{

		}

		/* Creates a RenderImageEvent
		*
		* @param texture the Texture to render
		* @param srcRect The source rectangle which determines what part of the texture will be rendered
		* @param dstRect The destination rectangle, which determins where on the screen the texture will be rendered
		*/
		RenderEvent(Rect* dstrect) : m_dstrect(dstrect)
		{
		}

		~RenderEvent()
		{
			delete m_dstrect;
		}

		Rect* getDstRect() { return m_dstrect; }
	};

	//An event which calls for the Graphics System to render an image
	class RenderImageEvent : public RenderEvent
	{
		Texture m_texture;
		Rect* m_srcRect;

	public:
		RenderImageEvent()
		{

		}

		/* Creates a RenderImageEvent
		*
		* @param texture the Texture to render
		* @param srcRect The source rectangle which determines what part of the texture will be rendered
		* @param dstRect The destination rectangle, which determins where on the screen the texture will be rendered
		*/
		RenderImageEvent(Texture texture, Rect* srcRect, Rect* dstRect) : m_texture(texture), m_srcRect(srcRect), RenderEvent(dstRect)
		{
		}

		~RenderImageEvent()
		{
			delete m_srcRect;
		}

		Rect* getSrcRect() { return m_srcRect; }
		Texture getTexture() { return m_texture; }
		virtual GraphicsEventType getGraphicsEventType() override { return GraphicsEventType::RENDERIMAGE; }
	};


	//TODO write graphics system

	class GraphicsSystem : public System
	{
	public:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		Color m_defaultRenderColor;


		//private because we don't want the user screwing with this
		void setRenderDrawColor(Color color);

	public:
		GraphicsSystem(evnt::EventBus* bus, std::string name, int x, int y, int w, int h);

		~GraphicsSystem();

		void eventFired(Event* evnt);

		/* Causes a graphics update
		*
		*/
		void update();


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
		void renderDrawRect(int x, int y, int w, int h, Color color);


		/* Draws an filled rectangle on the screen of the specified color
		*
		* @param x The x coordinate of the rectangle on the window
		* @param y The Y coordinate of the rectangle on the window
		* @param w The width of the rectangle
		* @param h The height of the rectangle
		* @param color The color of the rectangle
		*/
		void renderFillRect(int x, int y, int w, int h, Color color);

		/* Sets the default color to render objects
		*
		* @param color The color to set
		*/
		void setDefaultRenderColor(Color color);


		/* Loads an image into a Texture object
		*
		* @param file The filepath of the image
		*/
		Texture loadTexture(std::string filepath);


		/* Renders the supplied texture at the given position and size
		*
		* @param texture The texture to render
		* @param w The width of the texture once rendered
		* @param h The heigth of the texture once rendererd
		* @param x The X position of the texture once rendered
		* @param y The Y position of the texture once rendered
		*/
		void renderTexture(Texture texture, Rect* source, Rect* dest);
	};

}

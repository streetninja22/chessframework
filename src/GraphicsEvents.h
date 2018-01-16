#pragma once

#include "GraphicsSystem.h"


namespace gfx
{
	
	
	class LoadTextureEvent : public GraphicsEvent
	{
		
		
		
		virtual GraphicsEventType getGraphicsEventType() { return GraphicsEventType::DEFAULT; }
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
		virtual GraphicsEventType getGraphicsEventType() override { return GraphicsEventType::RENDER_IMAGE; }
	};

	class RenderDrawRectEvent : public RenderEvent
	{
		Rect* m_rect;
		Color m_color;
		
	public:
		
		/* Creates a RenderRectEvent
			*
			* @param rect The rectangle object which stores the size and position of the rect to draw
			* @param color The color to draw the rectangle in
			*/
		RenderDrawRectEvent(Rect* rect, Color color) : m_rect(rect), m_color(color)
		{
		}
		
		~RenderDrawRectEvent()
		{
			delete m_rect;
		}
		
		Rect* getRect() { return m_rect; } //nerf this scrubs
		Color getColor() { return m_color; }
		virtual GraphicsEventType getGraphicsEventType() override { return GraphicsEventType::RENDER_DRAW_RECT; }
	};

	class RenderFillRectEvent : public RenderEvent
	{
		Rect* m_rect;
		Color m_color;
		
	public:
		
		/* Creates a RenderRectEvent
		 *
		 * @param rect The rectangle object which stores the size and position of the rect to draw
		 * @param color The color to draw the rectangle in
		 */
		RenderFillRectEvent(Rect* rect, Color color) : m_rect(rect), m_color(color)
		{
		}
		
		~RenderFillRectEvent()
		{
			delete m_rect;
		}
		
		Rect* getRect() { return m_rect; } //nerf this scrubs
		Color getColor() { return m_color; }
		virtual GraphicsEventType getGraphicsEventType() override { return GraphicsEventType::RENDER_FILL_RECT; }
	};

	
}

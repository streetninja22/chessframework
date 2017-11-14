#pragma once

#include <functional>
#include <array>
#include <queue>

namespace evnt
{
	enum class EventType
	{
		DEFAULT,
		GRAPHICS,
		INPUT,
	};

	class Event
	{

		EventType m_type;

	public:
		Event()
		{

		}

		virtual ~Event()
		{

		}

		virtual EventType getEventType() { return m_type; }
	};
    
    typedef std::function<void(Event*)> EventListener;

	class EventBus
	{
		std::queue<Event*> m_eventQueue;
        std::vector<EventListener> m_eventListeners;

	public:
		EventBus() {}

		/* adds a listener function to the event bus
		* param listener The listener to add
		*/
		void addListener(std::function<void(Event*)> listener)
		{
			m_eventListeners.push_back(listener);
		}

		/* adds an event to the queue
		* param event the event to add
		*/
		void addEvent(Event* event)
		{
			m_eventQueue.push(event);
		}

		/* call the event listeners with the next event in queue
		*/
		void callListeners()
		{
			while (!m_eventQueue.empty())
			{
				for (auto& index : m_eventListeners)
					(index)(m_eventQueue.front());
				//delete m_eventQueue.front(); //this is causing errors, might as well have a dangling pointer for now while testing
				m_eventQueue.pop();
			}
		}

		void clearEventQueue()
		{
			for (int index = 0; index < m_eventQueue.size(); ++index)
			{
				delete m_eventQueue.front();
				m_eventQueue.pop();
			}
		}

		~EventBus()
		{
			clearEventQueue();
		}

	};

	class EventNode
	{
	protected:
		EventBus *m_eventBus;

		/* node event listener
		* param event the event which fired the function
		*/
		virtual void eventFired(Event* event)
		{

		}

		/* returns the class event listener
		*/
		std::function<void(Event*)> getEventListener()
		{
			auto eventListener = [=](Event* event) -> void {
				this->eventFired(event);
			};

			return eventListener;
		}

		/* adds event to the associated bus queue
		* param event the event to add
		*/
		void addEvent(Event* event)
		{
			m_eventBus->addEvent(event);
		}

	public:
		virtual void update()
		{

		}

		EventNode(EventBus* bus) : m_eventBus(bus)
		{
			bus->addListener(getEventListener());
		}

		virtual ~EventNode()
		{

		}
	};

}

#pragma once

#include <functional>
#include <array>
#include <queue>

namespace evnt
{

	class Event
	{

	public:
		Event()
		{

		}

		virtual ~Event()
		{

		}
	};

	class EventBus
	{
		std::queue<Event*> m_eventQueue;
		std::vector <std::function<void(Event*)>> m_eventListeners;

	public:
		EventBus() {}
		~EventBus() {}

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
				delete m_eventQueue.front();
				m_eventQueue.pop();
			}
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
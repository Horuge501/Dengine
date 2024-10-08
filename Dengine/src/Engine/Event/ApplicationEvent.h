#pragma once

#include "denjipch.h"
#include "Engine/core.h"
#include "Event.h"

namespace Denji {
	class DENJI_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: _width(width), _height(height) {}

		inline unsigned int GetWidth() const { return _width; }
		inline unsigned int GetHeight() const { return _height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Window resize event: " << _width << ", " << _height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int _width;
		unsigned int _height;
	};

	class DENJI_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
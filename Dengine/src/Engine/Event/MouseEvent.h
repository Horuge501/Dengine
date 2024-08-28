#pragma once

#include "denjipch.h"
#include "Engine/core.h"
#include "Event.h"

namespace Denji {
	class DENJI_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(int x, int y)
			: _MouseX(x), _MouseY(y) {}

		inline float GetX() const { return _MouseX; }
		inline float GeyY() const { return _MouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << _MouseX << ", " << _MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)


	private:
		float _MouseX, _MouseY;
	};

	class DENJI_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: _XOffset(xOffset), _YOffset(yOffset) {}

		inline float GetX() const { return _XOffset; }
		inline float GeyY() const { return _YOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << _XOffset << ", " << _YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)


	private:
		float _XOffset, _YOffset;
	};

	class DENJI_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return _button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)


	protected:
		MouseButtonEvent(int button) : _button(button) {}
		int _button;
	};

	class DENJI_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Mouse Button Pressed Event: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class DENJI_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Mouse Button Released Event: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
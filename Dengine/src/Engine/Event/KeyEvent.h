#pragma once

#include "denjipch.h"
#include "Engine/core.h"
#include "Event.h"

namespace Denji {
	class DENJI_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return _keyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)


	protected:
		KeyEvent(int keyCode) : _keyCode(keyCode){}
		int _keyCode;
	};

	class DENJI_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keyCode, int repeateCount)
			: KeyEvent(keyCode), _repeateCount(repeateCount) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Key Pressed Event: " << _keyCode << "(" << _repeateCount << ")";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int _repeateCount;
	};

	class DENJI_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Key Released Event: " << _keyCode;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(KeyReleased)

	};
}
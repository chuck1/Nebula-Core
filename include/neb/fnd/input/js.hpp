#ifndef NEB_CORE_INPUT_JS_HPP
#define NEB_CORE_INPUT_JS_HPP

#include <glm/glm.hpp>

#include <neb/fnd/input/signals.hpp>
#include <neb/fnd/input/util/decl.hpp>

namespace neb { namespace fnd { namespace input {
	class js
	{
	public:
		friend class sink;
		typedef neb::fnd::input::signals::JoystickButtonFun SIG;
		virtual int		get_axes_count() = 0;
		virtual int		get_button_count() = 0;
		virtual float		get_axes(int i) = 0;
	protected:
		SIG			joystickButtonFun_;
	};
}}}

#endif



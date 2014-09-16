#ifndef NEB_CORE_INPUT_SOURCE_HPP
#define NEB_CORE_INPUT_SOURCE_HPP

#include <glm/glm.hpp>

#include <neb/core/input/signals.hpp>

namespace neb { namespace core { namespace input {

	class source
	{
		public:


			virtual glm::vec2		getCursorPosNDC() = 0;

			// input signals
			struct
			{
				neb::core::input::signals::KeyFun		keyFun_;
				neb::core::input::signals::MouseButtonFun	mouseButtonFun_;
				neb::core::input::signals::CharFun		charFun_;
			} sig_;
			
			
			

	};

}}}

#endif


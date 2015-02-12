#ifndef NEB_CORE_INPUT_SOURCE_HPP
#define NEB_CORE_INPUT_SOURCE_HPP

#include <glm/glm.hpp>

#include <neb/core/input/signals.hpp>
#include <neb/core/input/util/decl.hpp>

namespace neb { namespace fnd { namespace input {
	class source
	{
		public:
			friend class sink;

			virtual glm::vec2		getCursorPosNDC() = 0;
		protected:
			// input signals
			struct
			{
				neb::fnd::input::signals::KeyFun		keyFun_;
				neb::fnd::input::signals::MouseButtonFun	mouseButtonFun_;
				neb::fnd::input::signals::CharFun		charFun_;
			} sig_;
	};
}}}

#endif

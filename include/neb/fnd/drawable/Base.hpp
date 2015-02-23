#ifndef NEB_CORE_DRAWABLE_BASE_HPP
#define NEB_CORE_DRAWABLE_BASE_HPP

#include <neb/fnd/RenderDesc.hpp>

namespace neb { namespace fnd { namespace drawable {
	class Base
	{
		public:
			virtual ~Base() = 0;
			virtual void		draw(neb::fnd::RenderDesc const & rd) = 0;
	};
}}}

#endif

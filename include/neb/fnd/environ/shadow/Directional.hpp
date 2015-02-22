#ifndef NEB_CORE_ENVIRON_SHADOW_DIRECTIONAL_HPP
#define NEB_CORE_ENVIRON_SHADOW_DIRECTIONAL_HPP

#include <neb/fnd/environ/shadow/Base.hpp>

namespace neb { namespace fnd { namespace environ { namespace shadow {
	class Directional:
		virtual public neb::fnd::environ::shadow::Base
	{
		public:
			virtual void		init(parent_t * const & p);
			virtual void		release();
	};
}}}}

#endif


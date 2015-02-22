#ifndef NEB_CORE_ENVIRON_SHADOW_POINT_HPP
#define NEB_CORE_ENVIRON_SHADOW_POINT_HPP

#include <neb/fnd/environ/shadow/Base.hpp>

namespace neb { namespace fnd { namespace environ { namespace shadow {
	class Point:
		virtual public neb::fnd::environ::shadow::Base
	{
		public:
			virtual void		init(parent_t * const & p);
			virtual void		release();
	};
}}}}

#endif

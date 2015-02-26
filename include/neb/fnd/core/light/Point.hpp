#ifndef NEB_CORE_CORE_LIGHT_POINT_HPP
#define NEB_CORE_CORE_LIGHT_POINT_HPP

#include <neb/fnd/core/light/base.hpp>

namespace neb { namespace fnd { namespace core { namespace light {
	class Point:
		virtual public neb::fnd::core::light::base
	{
		public:
			virtual void		init(parent_t * const & parent);
	};
}}}}

#endif

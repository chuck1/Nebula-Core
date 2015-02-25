#ifndef NEB_CORE_CORE_LIGHT_SPOT_HPP
#define NEB_CORE_CORE_LIGHT_SPOTT_HPP

#include <neb/fnd/core/light/base.hpp>

namespace neb { namespace fnd { namespace core { namespace light {
	class Spot:
		virtual public neb::fnd::core::light::base
	{
		public:
			virtual void	init(parent_t * const & parent);
			void		set_spot_direction(glm::vec3);
	};
}}}}

#endif

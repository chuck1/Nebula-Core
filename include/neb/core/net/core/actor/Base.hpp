#ifndef NEB_FND_NET_CORE_ACTOR_BASE_HPP
#define NEB_FND_NET_CORE_ACTOR_BASE_HPP

#include <neb/core/tmp/Child.hpp>

namespace neb { namespace fnd { namespace net { namespace core { namespace actor {
	class Base:
		virtual public neb::fnd::tmp::Child<neb::fnd::core::actor::base>
	{
		public:
			virtual void		init(parent_t * const & p) = 0;
			virtual void		v_set_pose_data(neb::fnd::math::pose const & pose) = 0;
	};
}}}}}

#endif

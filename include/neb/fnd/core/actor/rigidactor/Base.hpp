#ifndef NEB_FND_CORE_ACTOR_RIGID_ACTOR_BASE_HPP
#define NEB_FND_CORE_ACTOR_RIGID_ACTOR_BASE_HPP

#include <neb/fnd/core/actor/Base.hpp>

namespace neb { namespace fnd { namespace core { namespace actor { namespace rigidactor {
	class base:
		virtual public neb::fnd::core::actor::base
	{
	public:
		virtual void		set_pose_global(gal::math::pose pose);
	};

}}}}}

#endif

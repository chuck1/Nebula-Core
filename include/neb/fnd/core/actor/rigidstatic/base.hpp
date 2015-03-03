#ifndef NEB_FND_CORE_ACTOR_RIGID_STATIC_BASE_HPP
#define NEB_FND_CORE_ACTOR_RIGID_STATIC_BASE_HPP

#include <neb/fnd/core/actor/rigidactor/Base.hpp>

namespace neb { namespace fnd { namespace core { namespace actor { namespace rigidstatic {
	class base:
		public neb::fnd::core::actor::rigidactor::base
	{
	public:
		base();
		virtual ~base();
		virtual void				init(parent_t * const & p);
		virtual void				release();
		virtual void				step(gal::etc::timestep const & ts);
	};
}}}}}

#endif

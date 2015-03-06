#ifndef NEB_FND_CORE_ACTOR_RIGID_DYNAMIC_BASE_HPP
#define NEB_FND_CORE_ACTOR_RIGID_DYNAMIC_BASE_HPP

#include <neb/fnd/core/actor/rigidbody/Base.hpp>

namespace neb { namespace fnd { namespace core { namespace actor { namespace rigiddynamic {

	class base:
		virtual public neb::fnd::core::actor::rigidbody::base
	{
	public:
		base();
		~base();
		virtual void		init(parent_t * const &);
		virtual void		release();
		virtual void		step(gal::etc::timestep const & ts);
	};

}}}}}

#endif

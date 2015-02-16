#ifndef NEB_FND_CORE_ACTOR_RIGID_BODY_BASE_HPP
#define NEB_FND_CORE_ACTOR_RIGID_BODY_BASE_HPP

#include <neb/core/core/actor/rigidactor/base.hpp>

namespace neb { namespace fnd { namespace core { namespace actor { namespace rigidbody {
	class base:
		virtual public neb::fnd::core::actor::rigidactor::base
	{
		public:
			virtual void		createControlManual(std::shared_ptr<neb::fnd::input::source> window) = 0;
	};

}}}}}


#endif

#ifndef NEB_FND_CORE_ACTOR_RIGID_BODY_BASE_HPP
#define NEB_FND_CORE_ACTOR_RIGID_BODY_BASE_HPP

#include <neb/fnd/core/actor/rigidactor/Base.hpp>

#include <neb/fnd/core/actor/util/decl.hpp>

namespace neb { namespace fnd { namespace core { namespace actor { namespace rigidbody {
	class base:
		virtual public neb::fnd::core::actor::rigidactor::base
	{
		public:
			virtual void		createControlManual(std::shared_ptr<neb::fnd::input::source> window) = 0;
			glm::vec3		get_angular_velocity();
			glm::vec3		get_mass_space_inertia_tensor();
		//typedef shared_ptr<neb::phx::core::actor::control::rigidbody::base>	control_shared;
			typedef shared_ptr<neb::fnd::core::actor::control::rigidbody::base>	control_shared;
			control_shared		control_;
	};

}}}}}


#endif

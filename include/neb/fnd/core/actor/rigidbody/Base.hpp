#ifndef NEB_FND_CORE_ACTOR_RIGID_BODY_BASE_HPP
#define NEB_FND_CORE_ACTOR_RIGID_BODY_BASE_HPP

#include <neb/fnd/core/actor/rigidactor/Base.hpp>

#include <neb/fnd/core/actor/util/decl.hpp>

namespace neb { namespace fnd { namespace core { namespace actor { namespace rigidbody {
	class base:
		virtual public neb::fnd::core::actor::rigidactor::base
	{
	public:
		typedef std::shared_ptr<neb::fnd::core::actor::control::rigidbody::base> S_C;
		typedef std::weak_ptr<neb::fnd::core::actor::control::rigidbody::base> W_C;
		glm::vec3		get_angular_velocity();
		glm::vec3		get_mass_space_inertia_tensor();
		W_C			createControlManual(std::shared_ptr<neb::fnd::input::source> window);
		W_C			createControlPD();
		S_C			control_;
	};

}}}}}


#endif

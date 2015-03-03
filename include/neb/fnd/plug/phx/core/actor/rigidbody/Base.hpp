#ifndef NEB_FND_PLUG_PHX_CORE_ACTOR_RIGIDBODY_BASE_HPP
#define NEB_FND_PLUG_PHX_CORE_ACTOR_RIGIDBODY_BASE_HPP

#include <neb/fnd/plug/phx/core/actor/Base.hpp>

namespace neb { namespace fnd { namespace plug { namespace phx { namespace core { namespace actor { namespace rigidbody {
	class Base:
		virtual public neb::fnd::plug::phx::core::actor::Base
	{
		public:
			virtual glm::vec3		get_angular_velocity() = 0;
			virtual glm::vec3		get_mass_space_inertia_tensor() = 0;
	};
}}}}}}}

#endif

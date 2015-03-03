#ifndef NEB_FND_CORE_ACTOR_CONTROL_RIGIDBODY_PD_HPP
#define NEB_FND_CORE_ACTOR_CONTROL_RIGIDBODY_PD_HPP

#include <neb/fnd/core/actor/control/rigidbody/Base.hpp>

namespace neb { namespace fnd { namespace core { namespace actor { namespace control { namespace rigidbody {
	class PD:
		virtual public neb::fnd::core::actor::control::rigidbody::base
	{
		public:
			virtual ~PD();
			void				step(gal::etc::timestep const & ts);
			glm::vec3			getOrientationError();
			virtual glm::vec3		f_body();
			virtual glm::vec3		t_body();
			virtual glm::vec3		f_global();
			virtual glm::vec3		t_global();
	};
}}}}}}

#endif

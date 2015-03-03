#ifndef NEB_FND_CORE_ACTOR_CONTROL_RIGID_BODY_MANUAL_H__
#define NEB_FND_CORE_ACTOR_CONTROL_RIGID_BODY_MANUAL_H__

#include <neb/fnd/core/actor/control/rigidbody/Base.hpp>

namespace neb { namespace fnd { namespace core { namespace actor { namespace control { namespace rigidbody {
	class Manual:
		virtual public neb::fnd::core::actor::control::rigidbody::base
	{
		public:
			virtual ~Manual();
			void				step(gal::etc::timestep const & ts);
			virtual glm::vec3		f_body();
			virtual glm::vec3		t_body();
			virtual glm::vec3		f_global();
			virtual glm::vec3		t_global();
	};
}}}}}}

#endif

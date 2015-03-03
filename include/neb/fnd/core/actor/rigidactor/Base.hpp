#ifndef NEB_FND_CORE_ACTOR_RIGID_ACTOR_BASE_HPP
#define NEB_FND_CORE_ACTOR_RIGID_ACTOR_BASE_HPP

#include <neb/fnd/core/actor/actor/Base.hpp>

namespace neb { namespace fnd { namespace core { namespace actor { namespace rigidactor {
	class base:
		virtual public neb::fnd::core::actor::actor::base
	{
		public:
			typedef neb::fnd::core::shape::base SHAPE;
			//virtual void							init(neb::fnd::core::actor::util::parent * const & p) = 0;
			//virtual void							release() = 0;
			//virtual void							step(gal::etc::timestep const & ts) = 0;
			std::weak_ptr<SHAPE>		createShapeBoxUninitialized(glm::vec3 size);
			std::weak_ptr<SHAPE>		createShapeBox(gal::math::pose, glm::vec3 size);
			//virtual void			set_pose_global(gal::math::pose pose);
	};

}}}}}

#endif

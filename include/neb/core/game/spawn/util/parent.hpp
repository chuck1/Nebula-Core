#ifndef __GRU_GAME_SPAWN_UTIL_PARENT_H__
#define __GRU_GAME_SPAWN_UTIL_PARENT_H__

#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gal/itf/shared.hpp>

#include <neb/core/game/spawn/base.hpp>
#include <neb/core/util/parent.hpp>

namespace neb { namespace fnd { namespace game { namespace spawn { namespace util {
	/** @brief @Parent
	 * abstract class for parent of an @Actor
	 */
	class parent:
		virtual public neb::fnd::util::parent<neb::fnd::game::spawn::base, parent>
	{
		public:
			parent();
			virtual ~parent();
			virtual void		init();
			virtual void		spawn_actor(std::shared_ptr<neb::fnd::core::actor::base> actor);
			std::weak_ptr<neb::fnd::game::spawn::base>		create_spawn(neb::fnd::math::pose pose);
	};
}}}}}

#endif


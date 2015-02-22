#ifndef PHYSX_GAME_WEAPON_UTIL_PARENT_HPP
#define PHYSX_GAME_WEAPON_UTIL_PARENT_HPP

#include <neb/fnd/util/parent.hpp>
#include <neb/fnd/core/actor/util/Cast.hpp>
#include <neb/fnd/game/weapon/base.hpp>

namespace neb { namespace fnd { namespace game { namespace weapon { namespace util {
	/** @brief @Parent
	 * abstract class for parent of a shape
	 */
	class parent:
		virtual public neb::fnd::util::parent<neb::fnd::game::weapon::base, parent>,
		virtual public neb::fnd::core::actor::util::Cast
	{
		public:
			virtual ~parent();
			neb::fnd::app::Base * const		get_fnd_app();
	};
}}}}}

#endif

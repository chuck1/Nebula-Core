#ifndef PHYSX_GAME_WEAPON_UTIL_PARENT_HPP
#define PHYSX_GAME_WEAPON_UTIL_PARENT_HPP


#include <neb/core/util/parent.hpp>

#include <neb/core/game/weapon/base.hpp>

namespace neb { namespace core { namespace game { namespace weapon { namespace util {


	/** @brief @Parent
	 * abstract class for parent of a shape
	 */
	class parent:
		virtual public neb::core::util::parent<nc::game::weapon::base, parent>
	{
		public:
			virtual ~parent() {}
	};



}}}}}

#endif






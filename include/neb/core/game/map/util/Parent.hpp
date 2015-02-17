#ifndef NEB_FND_GAME_MAP_UTIL_PARENT_HPP
#define NEB_FND_GAME_MAP_UTIL_PARENT_HPP

#include <neb/core/util/parent.hpp>

#include <neb/core/game/game/util/Cast.hpp>
#include <neb/core/game/map/base.hpp>

namespace neb { namespace fnd { namespace game { namespace map { namespace util {
	/** @brief @Parent
	 * abstract class for parent of a shape
	 */
	class Parent:
		virtual public neb::fnd::util::parent<neb::fnd::game::map::Base, Parent>,
		virtual public neb::fnd::game::game::util::Cast
	{
		public:
			virtual ~Parent();
	};
}}}}}

#endif

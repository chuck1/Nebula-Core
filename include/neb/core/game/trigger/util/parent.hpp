#ifndef NEB_CORE_GAME_TRIGGER_UTIL_PARENT_HPP
#define NEB_CORE_GAME_TRIGGER_UTIL_PARENT_HPP

#include <map>

#include <gal/itf/shared.hpp>

#include <neb/core/util/parent.hpp>
#include <neb/core/game/trigger/base.hpp>

namespace neb { namespace core { namespace game { namespace trigger { namespace util {

	/** @brief @Parent
	 * abstract class for parent of an @Actor
	 */
	class parent:
		virtual public nc::util::parent<nc::game::trigger::base, parent>
	{
		public:
			virtual void						init() {}
	};

}}}}}

#endif


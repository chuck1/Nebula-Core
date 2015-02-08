#ifndef NEB_CORE_GAME_TRIGGER_UTIL_PARENT_HPP
#define NEB_CORE_GAME_TRIGGER_UTIL_PARENT_HPP

#include <map>

#include <gal/itf/shared.hpp>

#include <neb/core/util/parent.hpp>
#include <neb/core/game/trigger/base.hpp>
#include <neb/core/game/game/util/Cast.hpp>

namespace neb { namespace fnd { namespace game { namespace trigger { namespace util {

	/** @brief @Parent
	 * abstract class for parent of an @Actor
	 */
	class parent:
		virtual public neb::fnd::util::parent<neb::fnd::game::trigger::base, parent>,
		virtual public neb::fnd::game::game::util::Cast
	{
		public:
			virtual void				init();
			neb::fnd::app::Base* const		get_app();
	};

}}}}}

#endif


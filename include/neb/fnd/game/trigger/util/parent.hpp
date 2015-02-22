#ifndef NEB_CORE_GAME_TRIGGER_UTIL_PARENT_HPP
#define NEB_CORE_GAME_TRIGGER_UTIL_PARENT_HPP

#include <map>

#include <gal/itf/shared.hpp>

#include <neb/fnd/util/parent.hpp>
#include <neb/fnd/game/trigger/base.hpp>
#include <neb/fnd/game/map/util/Cast.hpp>

namespace neb { namespace fnd { namespace game { namespace trigger { namespace util {

	/** @brief @Parent
	 * abstract class for parent of an @Actor
	 */
	class parent:
		virtual public neb::fnd::util::parent<neb::fnd::game::trigger::base, parent>,
		virtual public neb::fnd::game::map::util::Cast
	{
		public:
			virtual void				init();
			virtual void				step(gal::etc::timestep const & ts);
			neb::fnd::app::Base* const		get_fnd_app();
	};

}}}}}

#endif


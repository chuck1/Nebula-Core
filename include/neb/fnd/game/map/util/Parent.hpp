#ifndef NEB_FND_GAME_MAP_UTIL_PARENT_HPP
#define NEB_FND_GAME_MAP_UTIL_PARENT_HPP

#include <neb/fnd/util/parent.hpp>

#include <neb/fnd/game/game/util/Cast.hpp>
#include <neb/fnd/game/map/base.hpp>

namespace neb { namespace fnd { namespace game { namespace map { namespace util {
	/** @brief @Parent
	 * abstract class for parent of a shape
	 */
	class Parent:
		virtual public neb::fnd::util::parent<neb::fnd::game::map::Base, Parent>,
		virtual public neb::fnd::game::game::util::Cast
	{
		public:
			typedef neb::fnd::util::parent<neb::fnd::game::map::Base, Parent> PARENT;
			//using neb::fnd::util::parent<neb::fnd::game::map::Base, Parent>::step;
			virtual ~Parent();
			typedef neb::fnd::game::map::Base M;
			virtual void			step(gal::etc::timestep const & ts);
			virtual std::weak_ptr<M>	create_map_dll(std::string & s);
			neb::fnd::app::Base*		get_fnd_app();
	};
}}}}}

#endif

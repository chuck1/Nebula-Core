#ifndef NEB_CORE_GAME_TRIGGER_HPP
#define NEB_CORE_GAME_TRIGGER_HPP

#include <gal/stl/child.hpp>

#include <neb/core/util/decl.hpp>
#include <neb/core/itf/shared.hpp>
#include <neb/core/game/trigger/util/parent.hpp>

namespace neb { namespace core { namespace game { namespace trigger {

	class base:
		virtual public nc::itf::shared,
		virtual public gal::stl::child<nc::game::trigger::util::parent>
	{
		public:
			typedef nc::game::trigger::util::parent	parent_t;

			base();
			virtual void					step(gal::etc::timestep const &);
			virtual void					doSomething() = 0;
	};

}}}}

#endif




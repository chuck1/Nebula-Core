#ifndef NEB_CORE_GAME_TRIGGER_HPP
#define NEB_CORE_GAME_TRIGGER_HPP

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/game/trigger/util/decl.hpp>

namespace neb { namespace fnd { namespace game { namespace trigger {
	class base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<neb::fnd::game::trigger::util::parent>
	{
		public:
			typedef neb::fnd::game::trigger::util::parent	parent_t;

			base();
			virtual void					step(gal::etc::timestep const &);
			virtual void					doSomething() = 0;
	};

}}}}

#endif




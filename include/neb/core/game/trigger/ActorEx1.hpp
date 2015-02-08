#ifndef NEB_GAME_TRIGGER_ACTOREX1_HPP
#define NEB_GAME_TRIGGER_ACTOREX1_HPP

#include <neb/core/core/actor/util/decl.hpp>
#include <neb/core/game/trigger/util/decl.hpp>
#include <neb/core/game/trigger/base.hpp>

namespace neb { namespace fnd { namespace game { namespace trigger {

	class ActorEx1: virtual public neb::fnd::game::trigger::base {
		public:
			ActorEx1(std::shared_ptr<neb::fnd::game::trigger::util::parent> parent);

			virtual void						connect(
					shared_ptr<neb::fnd::core::actor::base> actor);

			virtual void						doSomething();
	};
}}}}

#endif


#ifndef NEB_FND_GAME_MAP_BASE_HPP
#define NEB_FND_GAME_MAP_BASE_HPP

#include <gal/stl/verbosity.hpp>

#include <neb/fnd/tmp/Child.hpp>

#include <neb/fnd/core/scene/util/parent.hpp>

#include <neb/fnd/game/spawn/util/parent.hpp>
#include <neb/fnd/game/ai/util/parent.hpp>
#include <neb/fnd/game/trigger/util/parent.hpp>
#include <neb/fnd/game/map/util/decl.hpp>

namespace neb { namespace fnd { namespace game { namespace map {
	class Base:
		public gal::tmp::Verbosity<neb::fnd::game::map::Base>,
		virtual public neb::fnd::tmp::Child<neb::fnd::game::map::util::Parent>,
		virtual public neb::fnd::core::scene::util::parent,
		virtual public neb::fnd::game::spawn::util::parent,
		virtual public neb::fnd::game::ai::util::parent,
		virtual public neb::fnd::game::trigger::util::parent
	{
		public:
			using CHILD::get_fnd_app;
			using gal::tmp::Verbosity<neb::fnd::game::map::Base>::printv;
			typedef neb::fnd::core::scene::base S;
			Base();
			virtual void		init(parent_t * const & p);
			virtual void		step(gal::etc::timestep const & ts);
			virtual void		setup() = 0;
			virtual void		release();
			virtual std::weak_ptr<neb::fnd::core::scene::base>	createScene();
			std::shared_ptr<S>	get_scene();
			gal::math::pose		getPose() const;
			gal::math::pose		getPoseGlobal() const;
		private:
			//std::shared_ptr<S>	_M_scene;
	};
}}}}

#endif

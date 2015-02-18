#ifndef NEB_FND_GAME_MAP_BASE_HPP
#define NEB_FND_GAME_MAP_BASE_HPP

#include <neb/core/tmp/Child.hpp>
#include <neb/core/core/scene/base.hpp>
#include <neb/core/game/spawn/util/parent.hpp>
#include <neb/core/game/ai/util/parent.hpp>
#include <neb/core/game/trigger/util/parent.hpp>
#include <neb/core/game/map/util/decl.hpp>

namespace neb { namespace fnd { namespace game { namespace map {
	class Base:
		virtual public neb::fnd::tmp::Child<neb::fnd::game::map::util::Parent>,
		virtual public neb::fnd::game::spawn::util::parent,
		virtual public neb::fnd::game::ai::util::parent,
		virtual public neb::fnd::game::trigger::util::parent
	{
		public:
			using CHILD::get_fnd_app;
			typedef neb::fnd::core::scene::base S;
			Base();
			virtual void		init(parent_t * const & p);
			virtual void		step(gal::etc::timestep const & ts);
			virtual void		setup() = 0;
			virtual void		release();
			std::shared_ptr<S>	get_scene();
			void			set_scene(std::shared_ptr<S>);
		private:
			std::weak_ptr<S>	_M_scene;
	};
}}}}

#endif

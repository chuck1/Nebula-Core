#ifndef NEBULA_CORE_GAME_GAME_BASE_HPP
#define NEBULA_CORE_GAME_GAME_BASE_HPP

#include <neb/core/core/scene/util/decl.hpp>
#include <neb/core/game/game/util/decl.hpp>
#include <neb/core/game/trigger/util/parent.hpp>
#include <neb/core/game/map/util/Parent.hpp>
#include <neb/core/game/ai/util/parent.hpp>

namespace neb { namespace fnd { namespace game { namespace game {
	class base:
		virtual public neb::fnd::tmp::Child<neb::fnd::game::game::util::parent>,
		virtual public neb::fnd::game::trigger::util::parent,
		virtual public neb::fnd::game::map::util::Parent,
		virtual public neb::fnd::game::ai::util::parent
	{
		public:
			using CHILD::get_fnd_app;
			typedef neb::fnd::game::game::util::parent parent_t;
			virtual void					init(parent_t * const &);
			virtual void					release();
			virtual void					step(gal::etc::timestep const & ts);
			/** @brief %Scene.
			 * Currently a game is fully defined by a single scene.
			 * The game will load a scene from an Xml file.
			 */
			std::weak_ptr<neb::fnd::core::scene::base>		scene_;
			//gal::map<std::shared_ptr<neb::Game::Player> >   players_;
	};
}}}}

#endif


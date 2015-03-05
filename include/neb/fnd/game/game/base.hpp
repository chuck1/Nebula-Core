#ifndef NEBULA_CORE_GAME_GAME_BASE_HPP
#define NEBULA_CORE_GAME_GAME_BASE_HPP

#include <neb/fnd/core/scene/util/decl.hpp>

#include <neb/fnd/game/game/util/decl.hpp>
#include <neb/fnd/game/game/desc.hpp>

#include <neb/fnd/game/trigger/util/parent.hpp>
#include <neb/fnd/game/map/util/Parent.hpp>
#include <neb/fnd/game/ai/util/parent.hpp>

namespace neb { namespace fnd { namespace game { namespace game {
	class base:
		virtual public neb::fnd::tmp::Child<neb::fnd::game::game::util::parent>,
		virtual public neb::fnd::game::map::util::Parent
	{
		public:
			using CHILD::get_fnd_app;
			//typedef neb::fnd::game::game::util::parent parent_t;
			virtual void				init(parent_t * const &);
			virtual void				release();
			virtual void				step(
					gal::etc::timestep const & ts);
			int					get_net_type();
			/** @brief %Scene.
			 * Currently a game is fully defined by a single scene.
			 * The game will load a scene from an Xml file.
			 */
			//std::weak_ptr<neb::fnd::core::scene::base>		scene_;
			//gal::map<std::shared_ptr<neb::Game::Player> >   players_;
			neb::fnd::game::game::desc		_M_desc;
	};
}}}}

#endif


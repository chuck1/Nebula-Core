#ifndef NEBULA_CORE_GAME_GAME_BASE_HPP
#define NEBULA_CORE_GAME_GAME_BASE_HPP

#include <neb/core/core/scene/util/decl.hpp>
#include <neb/core/game/game/util/decl.hpp>
#include <neb/core/game/trigger/util/parent.hpp>
#include <neb/core/game/ai/util/parent.hpp>

namespace neb { namespace core { namespace game { namespace game {
	class base:
		virtual public gal::stl::child<nc::game::game::util::parent>,
		virtual public neb::core::game::trigger::util::parent,
		virtual public neb::core::game::ai::util::parent
	{
		public:
			typedef nc::game::game::util::parent parent_t;
			virtual void					init(parent_t * const &);
			virtual void					release();
			virtual void					step(gal::etc::timestep const & ts);
			/** @brief %Scene.
			 * Currently a game is fully defined by a single scene.
			 * The game will load a scene from an Xml file.
			 */
			std::weak_ptr<nc::core::scene::base>		scene_;
			//gal::map<std::shared_ptr<neb::Game::Player> >   players_;
	};
}}}}

#endif


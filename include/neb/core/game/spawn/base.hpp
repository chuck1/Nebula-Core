#ifndef NEBULA_GAME_SPAWN_BASE_HPP
#define NEBULA_GAME_SPAWN_BASE_HPP

#include <neb/core/util/decl.hpp>
#include <neb/core/itf/shared.hpp>
#include <neb/core/math/pose.hpp>
#include <neb/core/game/spawn/util/decl.hpp>

namespace neb { namespace fnd { namespace game { namespace spawn {

	class base:
		virtual public neb::fnd::itf::shared
	{
		public:
			typedef neb::fnd::game::spawn::util::parent parent_t;

			neb::fnd::math::pose		pose_;

			virtual void			init(parent_t * const & p);			
			virtual void			step(gal::etc::timestep const &);

	};


}}}}

#endif

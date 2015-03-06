#ifndef NEBULA_GAME_SPAWN_BASE_HPP
#define NEBULA_GAME_SPAWN_BASE_HPP

#include <gal/math/pose.hpp>

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/game/spawn/util/decl.hpp>

namespace neb { namespace fnd { namespace game { namespace spawn {
	class base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<neb::fnd::game::spawn::util::parent>
	{
		public:
			virtual void			init(parent_t * const & p);			
			virtual void			step(gal::etc::timestep const &);
			gal::math::pose		pose_;
	};
}}}}

#endif

#ifndef NEBULA_GAME_SPAWN_BASE_HPP
#define NEBULA_GAME_SPAWN_BASE_HPP

#include <neb/core/pose.hpp>

namespace neb { namespace game { namespace spawn {

	class base: virtual public neb::itf::shared {
		public:

			neb::core::pose		pose_;
			
			virtual void		step(gal::etc::timestep const &) {}
			
	};

	
}}}

#endif

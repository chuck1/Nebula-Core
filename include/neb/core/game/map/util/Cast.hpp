#ifndef NEB_FND_GAME_MAP_UTIL_CAST_HPP
#define NEB_FND_GAME_MAP_UTIL_CAST_HPP

#include <neb/core/itf/shared.hpp>
#include <neb/core/game/map/util/decl.hpp>

namespace neb { namespace fnd { namespace game { namespace map { namespace util {
	class Cast:
		virtual public neb::fnd::itf::shared
	{
		public:
			typedef neb::fnd::game::map::base G;
			virtual std::shared_ptr<G>	is_fnd_game_map_base();
	};
}}}}}

#endif

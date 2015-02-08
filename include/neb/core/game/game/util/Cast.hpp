#ifndef NEB_FND_GAME_GAME_UTIL_CAST_HPP
#define NEB_FND_GAME_GAME_UTIL_CAST_HPP

#include <neb/core/itf/shared.hpp>
#include <neb/core/game/game/util/decl.hpp>

namespace neb { namespace fnd { namespace game { namespace game { namespace util {
	class Cast:
		virtual public neb::fnd::itf::shared
	{
		public:
			typedef neb::fnd::game::game::base G;
			virtual std::shared_ptr<G>	is_fnd_game_game_base();
	};
}}}}}

#endif

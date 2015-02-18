#include <neb/core/game/map/util/Cast.hpp>
#include <neb/core/game/map/base.hpp>

typedef neb::fnd::game::map::util::Cast THIS;

std::shared_ptr<THIS::G>	THIS::is_fnd_game_map_base()
{
	auto g = std::dynamic_pointer_cast<G>(shared_from_this());
	return g;
}


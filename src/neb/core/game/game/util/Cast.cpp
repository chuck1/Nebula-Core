#include <neb/core/game/game/base.hpp>
#include <neb/core/game/game/util/Cast.hpp>

typedef neb::fnd::game::game::util::Cast THIS;

std::shared_ptr<neb::fnd::game::game::base>	THIS::is_fnd_game_game_base()
{
	auto game = std::dynamic_pointer_cast<neb::fnd::game::game::base>(shared_from_this());
	return game;
}


#include <neb/fnd/game/game/util/parent.hpp>
#include <neb/fnd/game/game/base.hpp>
#include <neb/fnd/game/map/base.hpp>
#include <neb/fnd/game/trigger/util/parent.hpp>

typedef neb::fnd::game::trigger::util::parent THIS;

void				THIS::init()
{
}
void				THIS::step(gal::etc::timestep const & ts)
{
}
neb::fnd::app::Base* const	THIS::get_fnd_app()
{
	auto map = is_fnd_game_map_base();

	assert(map);

	return map->get_fnd_app();
}


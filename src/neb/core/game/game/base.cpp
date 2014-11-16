
#include <neb/core/game/game/base.hpp>

void		nc::game::game::base::init(parent_t * const & p)
{
}
void		nc::game::game::base::release()
{
}
void		nc::game::game::base::step(gal::etc::timestep const & ts)
{
	nc::game::ai::util::parent::step(ts);
	nc::game::trigger::util::parent::step(ts);
}


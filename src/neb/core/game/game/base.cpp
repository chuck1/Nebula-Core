
#include <neb/core/game/game/base.hpp>

void		neb::fnd::game::game::base::init(parent_t * const & p)
{
}
void		neb::fnd::game::game::base::release()
{
}
void		neb::fnd::game::game::base::step(gal::etc::timestep const & ts)
{
	neb::fnd::game::ai::util::parent::step(ts);
	neb::fnd::game::trigger::util::parent::step(ts);
}


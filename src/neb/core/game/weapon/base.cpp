#include <neb/core/game/weapon/base.hpp>

typedef neb::fnd::game::weapon::base THIS;

THIS::base():
	last_(0),
	cooldown_(1.0)
{
}
void		THIS::init(parent_t * const & p)
{
	setParent(p);
}
void		THIS::step(gal::etc::timestep const &)
{
}


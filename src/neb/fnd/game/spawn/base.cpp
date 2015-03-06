#include <neb/fnd/game/spawn/util/parent.hpp>
#include <neb/fnd/game/spawn/base.hpp>

typedef neb::fnd::game::spawn::base THIS;

void		THIS::init(parent_t * const & p)
{
	setParent(p);
}
void		THIS::step(gal::etc::timestep const &)
{
}



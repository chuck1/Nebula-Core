#include <neb/fnd/game/game/util/parent.hpp>

#include <neb/fnd/game/game/base.hpp>

typedef neb::fnd::game::game::base THIS;

void		THIS::init(parent_t * const & p)
{
	setParent(p);

	neb::fnd::game::map::util::Parent::init(p);
}
void		THIS::release()
{
}
void		THIS::step(gal::etc::timestep const & ts)
{
	printv_func(DEBUG);
	M::step(ts);
}
int		THIS::get_net_type()
{
	return _M_desc._M_net_type;
}



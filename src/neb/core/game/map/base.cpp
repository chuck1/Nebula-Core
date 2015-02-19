#include <neb/core/game/map/base.hpp>

typedef neb::fnd::game::map::Base THIS;

THIS::Base()
{
}
void		THIS::init(parent_t * const & p)
{


}
void		THIS::release()
{
	neb::fnd::game::spawn::util::parent::clear();
}
void		THIS::step(gal::etc::timestep const & ts)
{
	neb::fnd::game::ai::util::parent::step(ts);
	neb::fnd::game::trigger::util::parent::step(ts);
}
std::shared_ptr<neb::fnd::core::scene::base>	THIS::get_scene()
{
	auto s = _M_scene.lock();
	assert(s);
	return s;
}
void						THIS::set_scene(std::shared_ptr<S> s)
{
	assert(s);
	_M_scene = s;
}


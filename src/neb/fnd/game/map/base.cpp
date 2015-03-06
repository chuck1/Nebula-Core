#include <neb/fnd/game/map/util/Parent.hpp>
#include <neb/fnd/game/map/base.hpp>

typedef neb::fnd::game::map::Base THIS;

THIS::Base()
{
}
void		THIS::init(parent_t * const & p)
{
	printv_func(DEBUG);

	setParent(p);

	neb::fnd::core::scene::util::parent::init(p);
	neb::fnd::game::spawn::util::parent::init(p);
}
void		THIS::release()
{
	printv_func(DEBUG);

	neb::fnd::core::scene::util::parent::clear();
	neb::fnd::game::spawn::util::parent::clear();
}
void		THIS::step(gal::etc::timestep const & ts)
{
	printv_func(DEBUG);

	neb::fnd::core::scene::util::parent::step(ts);
	neb::fnd::game::ai::util::parent::step(ts);
	neb::fnd::game::trigger::util::parent::step(ts);
}
std::shared_ptr<neb::fnd::core::scene::base>		THIS::get_scene()
{
	printv_func(DEBUG);

	//auto s = _M_scene;
	auto s = neb::fnd::core::scene::util::parent::front();
	assert(s);
	return s;
}
std::weak_ptr<neb::fnd::core::scene::base>		THIS::createScene()
{
	printv_func(DEBUG);

	typedef neb::fnd::core::scene::base T;
	
	std::shared_ptr<T> scene (new T, gal::stl::deleter<T>());
	
	neb::fnd::core::scene::util::parent::insert(scene);

	scene->init(this);

	// map mod stuff
	/// @TODO how to cope with multiple scenes? should there even be multiple scenes?
	setup();

	return scene;
}
gal::math::pose			THIS::getPose() const
{
	return gal::math::pose();
}
gal::math::pose			THIS::getPoseGlobal() const
{
	return gal::math::pose();
}



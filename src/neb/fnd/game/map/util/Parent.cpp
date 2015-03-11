#include <neb/fnd/game/game/base.hpp>
#include <neb/fnd/game/game/util/parent.hpp>

#include <neb/fnd/game/map/util/Parent.hpp>

typedef neb::fnd::game::map::util::Parent THIS;

THIS::~Parent()
{
}
neb::fnd::app::Base*	THIS::get_fnd_app()
{
	auto g = is_fnd_game_game_base();
	assert(g);
	
	return g->get_fnd_app();
}
std::weak_ptr<THIS::M>	THIS::create_map_dll(std::string & s)
{
	//LOG(lg, neb::fin::sl, debug) << __PRETTY_FUNCTION__;
	
	//auto self(dynamic_pointer_cast<neb::fin::app::base>(shared_from_this()));

	typedef neb::fnd::game::map::Base		T;
	typedef gal::dll::helper<T>			H;

	std::shared_ptr<H> h(new H(s));

	h->open();
	
	h->add<T>("map");
	
	std::shared_ptr<T> map = h->make_shared<T>();

	gal::weak_ptr<T> w(map);

	//neb::fnd::game::map::util::parent::insert(scene);
	insert(std::move(map));

	w->init(this);

	return w;
}
void			THIS::step(gal::etc::timestep const & ts)
{
	PARENT::step(ts);
}


#include <neb/core/game/map/util/Parent.hpp>
#include <neb/core/game/game/base.hpp>
#include <neb/core/game/game/util/parent.hpp>

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

	//neb::fnd::game::map::util::parent::insert(scene);
	insert(map);

	map->init(this);

	return map;
}


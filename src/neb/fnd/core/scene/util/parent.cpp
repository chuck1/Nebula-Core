#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/game/map/base.hpp>
#include <neb/fnd/core/scene/util/parent.hpp>

typedef neb::fnd::core::scene::util::parent THIS;

neb::fnd::app::Base * const	THIS::get_fnd_app()
{
	auto map = dynamic_cast<neb::fnd::game::map::Base*>(this);
	assert(map);

	auto app = map->get_fnd_app();

	return app;
}


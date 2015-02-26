#include <neb/fnd/core/actor/Base.hpp>
#include <neb/fnd/game/weapon/util/parent.hpp>

typedef neb::fnd::game::weapon::util::parent THIS;

THIS::~parent()
{
}
neb::fnd::app::Base * const		THIS::get_fnd_app()
{
	auto actor = is_fnd_actor_base();
	assert(actor);
	return actor->get_fnd_app();
}


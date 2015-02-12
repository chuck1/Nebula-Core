#include <gal/log/log.hpp>

#include <neb/core/util/log.hpp>
#include <neb/core/util/config.hpp>
#include <neb/core/util/debug.hpp>
#include <neb/core/core/actor/base.hpp>
#include <neb/core/core/actor/util/parent.hpp>
#include <neb/core/core/scene/util/parent.hpp>
#include <neb/core/core/scene/base.hpp>

typedef neb::fnd::core::actor::util::parent THIS;

THIS::parent()
{
}
neb::fnd::core::actor::util::parent::~parent()
{
}
neb::fnd::app::Base * const	THIS::get_fnd_app()
{
	auto s = isSceneBase();
	if(s) return s->get_fnd_app();

	auto a = is_fnd_actor_base();
	//if(a) return a->get_fnd_app();
	assert(a);
	return a->get_fnd_app();
}


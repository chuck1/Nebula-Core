#include <gal/log/log.hpp>

#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/plug/gfx/core/actor/util/decl.hpp>
#include <neb/fnd/plug/gfx/core/actor/Base.hpp>

#include <neb/fnd/plug/phx/core/actor/util/decl.hpp>
#include <neb/fnd/plug/phx/core/actor/Base.hpp>

#include <neb/fnd/core/actor/rigidstatic/base.hpp>

typedef neb::fnd::core::actor::rigidstatic::base THIS;

THIS::base()
{
}
THIS::~base()
{
	printv_func(DEBUG);
}
void						THIS::init(parent_t * const & p)
{
	printv_func(DEBUG);

	setParent(p);

	auto app = get_fnd_app();

	if(!G::has_object())
		G::make_object<THIS, int>(
				app->get_graphics_plugin(),
				neb::fnd::plug::gfx::core::actor::type::RIGIDSTATIC);

	if(!P::has_object())
		P::make_object<THIS, int>(
				app->get_physics_plugin(),
				neb::fnd::plug::phx::core::actor::type::RIGIDSTATIC);

	neb::fnd::core::actor::base::init(p);

	//neb::gfx::core::actor::base::init(p);

	//neb::phx::core::actor::base::init(p);
	//neb::phx::core::actor::actor::base::init();
	//neb::phx::core::actor::rigidactor::base::init();
	//neb::phx::core::actor::rigidstatic::base::init();

	//neb::fin::core::actor::base::init(p);
	//neb::fin::core::actor::rigidactor::base::init();
}
void			THIS::step(gal::etc::timestep const & ts)
{
}
void			THIS::release()
{
}




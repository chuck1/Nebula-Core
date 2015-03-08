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

	if(app->G::has_object())
	if(!G::has_object())
		G::make_object<THIS, int>(
				app->get_graphics_plugin(),
				neb::fnd::plug::gfx::core::actor::type::RIGIDSTATIC);

	if(app->P::has_object())
	if(!P::has_object())
		P::make_object<THIS, int>(
				app->get_physics_plugin(),
				neb::fnd::plug::phx::core::actor::type::RIGIDSTATIC);

	neb::fnd::core::actor::base::init(p);

}
void			THIS::step(gal::etc::timestep const & ts)
{
}
void			THIS::release()
{
	neb::fnd::core::actor::base::release();
}




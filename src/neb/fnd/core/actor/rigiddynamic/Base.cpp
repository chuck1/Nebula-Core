
#include <gal/stl/verbosity.hpp>

#include <neb/fnd/app/Base.hpp>

#include <neb/fnd/plug/gfx/core/actor/util/decl.hpp>
#include <neb/fnd/plug/gfx/core/actor/Base.hpp>

#include <neb/fnd/plug/phx/core/actor/util/decl.hpp>
#include <neb/fnd/plug/phx/core/actor/Base.hpp>

#include <neb/fnd/core/actor/control/rigidbody/Manual.hpp>
#include <neb/fnd/core/actor/control/rigidbody/PD.hpp>

//#include <neb/phx/core/actor/control/rigidbody/base.hpp>

#include <neb/fnd/core/actor/rigiddynamic/Base.hpp>

typedef neb::fnd::core::actor::rigiddynamic::base THIS;

THIS::base()
{
}
THIS::~base() 
{
	printv_func(DEBUG);
}
void			THIS::init(parent_t * const & p)
{
	printv_func(DEBUG);

	setParent(p);

	auto app = get_fnd_app();

	if(!G::has_object())
		G::make_object<THIS, int>(
				app->get_graphics_plugin(),
				neb::fnd::plug::gfx::core::actor::type::RIGIDDYNAMIC);

	if(!P::has_object())
		P::make_object<THIS, int>(
				app->get_physics_plugin(),
				neb::fnd::plug::phx::core::actor::type::RIGIDDYNAMIC);

	neb::fnd::core::actor::base::init(p);

	//neb::phx::core::actor::base::init(p);
	//neb::phx::core::actor::actor::base::init();
	//neb::phx::core::actor::rigidactor::base::init();
	//neb::phx::core::actor::rigidbody::base::init();
	//neb::phx::core::actor::rigiddynamic::base::init();

	//neb::gfx::core::actor::base::init(p);

	//neb::fin::core::actor::base::init(p);
	//neb::fin::core::actor::rigidactor::base::init();
}
void					THIS::release()
{
	printv_func(DEBUG);

	neb::fnd::core::actor::base::release();

	//neb::phx::core::actor::base::release();
	//neb::phx::core::actor::actor::base::release();
	//neb::phx::core::actor::rigidactor::base::release();
	//neb::phx::core::actor::rigidbody::base::release();
	//neb::phx::core::actor::rigiddynamic::base::release();

	//neb::gfx::core::actor::base::release();

	//neb::fin::core::actor::base::release();
}
void					THIS::step(
		gal::etc::timestep const & ts)
{
	printv_func(DEBUG);

	neb::fnd::core::actor::base::step(ts);

	//neb::phx::core::actor::base::step(ts);
	//neb::phx::core::actor::actor::base::step(ts);
	//neb::phx::core::actor::rigidactor::base::step(ts);
	//neb::phx::core::actor::rigidbody::base::step(ts);
	//neb::phx::core::actor::rigiddynamic::base::step(ts);

	//neb::gfx::core::actor::base::step(ts);

	//neb::fin::core::actor::base::step(ts);

}


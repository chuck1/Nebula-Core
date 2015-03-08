#include <neb/fnd/app/Base.hpp>

#include <neb/fnd/plug/phx/core/shape/Base.hpp>

#include <neb/fnd/plug/gfx/core/shape/Base.hpp>
#include <neb/fnd/plug/gfx/core/shape/util/decl.hpp>

//#include <neb/fin/core/shape/box.hpp>
//#include <neb/fin/core/shape/util/parent.hpp>

#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/core/shape/Cuboid.hpp>

typedef neb::fnd::core::shape::Cuboid THIS;

THIS::Cuboid()
{
}
THIS::~Cuboid()
{
	printv_func(DEBUG);
}
void		THIS::init(parent_t * const & p)
{
	printv_func(DEBUG);

	setParent(p);

	auto app = get_fnd_app();

	if(app->G::has_object())
		if(!G::has_object())
			G::make_object<THIS, int>(
					app->get_graphics_plugin(),
					neb::fnd::plug::gfx::core::shape::type::CUBOID);

	if(app->P::has_object()) {
		if(P::has_object()) {
			printv(DEBUG, "phx plugin not null\n");
		} else {
			P::make_object<THIS, int>(
					app->get_physics_plugin(),
					neb::fnd::plug::phx::core::shape::type::CUBOID);
		}
	}

	neb::fnd::core::shape::base::init(p);

	//neb::gfx::core::shape::base::init(p);
	//neb::gfx::core::shape::box::init(p);

	//neb::phx::core::shape::base::init(p);
	//neb::phx::core::shape::box::init(p);

	//neb::fin::core::shape::base::init(p);
}
void		THIS::release()
{
	printv_func(DEBUG);

	neb::fnd::core::shape::base::release();

	//neb::gfx::core::shape::base::release();
	//neb::gfx::core::shape::box::release();

	//neb::phx::core::shape::base::release();
	//neb::phx::core::shape::box::release();

	//neb::fin::core::shape::base::release();

	G::reset();
	P::reset();
}
void		THIS::step(gal::etc::timestep const & ts)
{
	printv_func(DEBUG);
}
void		THIS::load(ba::polymorphic_iarchive & ar, unsigned int const & v)
{
	printv_func(DEBUG);

	gal::itf::shared::serialize(ar, v);//load(ar, v);
	neb::fnd::core::shape::base::load(ar, v);
}
void		THIS::save(ba::polymorphic_oarchive & ar, unsigned int const & v) const
{
	printv_func(DEBUG);

	const_cast<THIS*>(this)->gal::itf::shared::serialize(ar, v);//save(ar, v);
	neb::fnd::core::shape::base::save(ar, v);
}



#include <neb/fnd/core/shape/HeightField.hpp>

typedef neb::fnd::core::shape::HeightField::Base THIS;

THIS::Base()
{
}
void			THIS::init(THIS::parent_t * const & p)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	
	setParent(p);
	
	abort();

	//P::make_object<>

	//neb::fnd::core::shape::base::__init(p);
	//neb::gfx::core::shape::base::__init(p);
	//neb::phx::core::shape::HeightField::Base::__init(p);
}
void			THIS::release()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	
	neb::fnd::core::shape::base::__release();
	//neb::gfx::core::shape::base::__release();
	//neb::phx::core::shape::base::__release();
}
void		THIS::step(gal::etc::timestep  const & ts)
{
}
void		THIS::load(ba::polymorphic_iarchive & ar, unsigned int const &)
{
}
void		THIS::save(ba::polymorphic_oarchive & ar, unsigned int const &) const
{
}
/*
void		THIS::v_set_pose_data(gal::math::pose const & pose_global)
{
	abort();
}
*/


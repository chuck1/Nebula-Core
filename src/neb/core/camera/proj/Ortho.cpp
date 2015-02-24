#include <neb/fnd/camera/proj/Ortho.hpp>

typedef neb::fnd::camera::proj::Ortho THIS;

THIS::Ortho()
{
}
void		THIS::init(parent_t * const & p)
{
	setParent(p);
}
void		THIS::step(gal::etc::timestep const & p)
{
}
void		THIS::release()
{
}




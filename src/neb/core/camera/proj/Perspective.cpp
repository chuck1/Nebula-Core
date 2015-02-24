#include <neb/fnd/camera/proj/Perspective.hpp>

typedef neb::fnd::camera::proj::Perspective THIS;

THIS::Perspective()
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




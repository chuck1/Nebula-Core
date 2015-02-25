#include <neb/fnd/camera/proj/Perspective.hpp>

#include <neb/fnd/plug/gfx/camera/proj/Base.hpp>

typedef neb::fnd::camera::proj::Perspective THIS;

THIS::Perspective()
{
}
void		THIS::init(parent_t * const & p)
{
	setParent(p);
	
	if(G::has_object())
		G::get_object()->calculate();
}
void		THIS::step(gal::etc::timestep const & p)
{
}
void		THIS::release()
{
}




#include <neb/fnd/camera/view/Base.hpp>
#include <neb/fnd/plug/gfx/camera/view/Base.hpp>

typedef neb::fnd::camera::view::Base THIS;

void		THIS::init(parent_t * const & p)
{
	setParent(p);
}
void		THIS::load(neb::fnd::glsl::program::Base * const & p)
{
	if(G::has_object())
		G::get_object()->load(p);
}



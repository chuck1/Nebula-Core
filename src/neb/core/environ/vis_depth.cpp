#include <neb/fin/environ/visualization/Depth.hpp>

typedef neb::fin::environ::visualization::Depth THIS;

void			THIS::init(parent_t * const & p)
{
	setParent(p);

	//neb::gfx::environ::vis_depth::init(p);
	neb::fnd::environ::Base::init(p);

}

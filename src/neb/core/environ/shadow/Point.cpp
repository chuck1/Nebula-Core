#include <neb/fnd/environ/shadow/Point.hpp>

typedef neb::fnd::environ::shadow::Point THIS;

void			THIS::release()
{
}
void			THIS::init(parent_t * const & p)
{
	setParent(p);

//	neb::gfx::environ::shadow::point::init(p);
	neb::fnd::environ::Base::init(p);
}


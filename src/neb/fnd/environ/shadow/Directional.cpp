#include <neb/fnd/environ/shadow/Directional.hpp>

typedef neb::fnd::environ::shadow::Directional THIS;

void			THIS::release()
{
}
void			THIS::init(parent_t * const & p)
{
	setParent(p);

	//neb::fnd::environ::shadow::Directional::init(p);
}


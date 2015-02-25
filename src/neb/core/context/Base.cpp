#include <neb/fnd/context/Base.hpp>
#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/plug/gfx/context/Base.hpp>

typedef neb::fnd::context::Base THIS;

void			THIS::render()
{
	//if(G::has_object())
	G::get_object()->render();
}
void			THIS::step(gal::etc::timestep const & ts)
{
}
/*
*/


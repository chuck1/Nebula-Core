#include <neb/fnd/context/Base.hpp>
#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/plug/gfx/context/Base.hpp>

typedef neb::fnd::context::Base THIS;

void			THIS::render()
{
	if(_M_graphics_object)
		_M_graphics_object->render();
}
void			THIS::step(gal::etc::timestep const & ts)
{
}
void			THIS::setDrawable(std::shared_ptr<neb::fnd::drawable::Base> d)
{
	auto e = neb::fnd::environ::util::Parent::front();
	assert(e);

	e->drawable_ = d;
}



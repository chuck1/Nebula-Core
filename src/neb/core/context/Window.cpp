#include <neb/fnd/context/Window.hpp>

#include <neb/fnd/plug/gfx/context/Base.hpp>

typedef neb::fnd::context::Window THIS;

void		THIS::init(parent_t * const parent)
{
	setParent(parent);

	//neb::fin::context::Base::init(parent);
	//neb::gfx::context::Window::init(parent);
}
void		THIS::step(gal::etc::timestep const & ts)
{
}
void		THIS::render()
{
	if(_M_graphics_object)
		_M_graphics_object->render();
	//neb::gfx::context::Window::render();
}


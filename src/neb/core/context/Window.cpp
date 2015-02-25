#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/context/Window.hpp>

#include <neb/fnd/plug/gfx/context/util/decl.hpp>
#include <neb/fnd/plug/gfx/context/Base.hpp>

typedef neb::fnd::context::Window THIS;

void		THIS::init(parent_t * const parent)
{
	setParent(parent);

	auto app = get_fnd_app();

	G::make_object<THIS, int>(app->_M_graphics_plugin, neb::fnd::plug::gfx::context::type::WINDOW);

	//neb::fin::context::Base::init(parent);
	//neb::gfx::context::Window::init(parent);
}
void		THIS::step(gal::etc::timestep const & ts)
{
}
void		THIS::render()
{
	if(G::has_object())
		G::get_object()->render();
	//neb::gfx::context::Window::render();
}


#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/environ/Two.hpp>

#include <neb/fnd/plug/gfx/environ/Base.hpp>

typedef neb::fnd::environ::Two THIS;

void		THIS::init(parent_t * const & parent)
{
	setParent(parent);

	auto app = get_fnd_app();

	if(app->G::has_object())
	G::make_object<THIS, int>(
			app->get_graphics_plugin(),
			neb::fnd::plug::gfx::environ::type::TWO);
}
void		THIS::release()
{
}


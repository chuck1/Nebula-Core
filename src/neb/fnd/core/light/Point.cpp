#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/core/light/util/parent.hpp>
#include <neb/fnd/core/light/Point.hpp>

#include <neb/fnd/plug/gfx/core/light/Base.hpp>
#include <neb/fnd/plug/gfx/core/light/util/decl.hpp>

typedef neb::fnd::core::light::Point THIS;

void			THIS::init(parent_t * const & parent)
{
	printv_func(DEBUG);

	setParent(parent);

	auto app = get_fnd_app();

	if(app->G::has_object())
	if(!G::has_object())
		G::make_object<THIS, int>(
				app->get_graphics_plugin(),
				neb::fnd::plug::gfx::core::light::type::POINT);
}


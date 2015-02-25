#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/core/light/Directional.hpp>

#include <neb/fnd/plug/gfx/core/light/util/decl.hpp>
#include <neb/fnd/plug/gfx/core/light/Base.hpp>

typedef neb::fnd::core::light::Directional THIS;

void		THIS::init(parent_t * const & parent)
{
	setParent(parent);

	auto app = get_fnd_app();

	G::make_object<THIS, int>(app->_M_graphics_plugin, neb::fnd::plug::gfx::core::light::type::DIRECTIONAL);

	neb::fnd::core::light::base::init(parent);
}


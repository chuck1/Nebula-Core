#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/core/light/Spot.hpp>

#include <neb/fnd/plug/gfx/core/light/util/decl.hpp>

typedef neb::fnd::core::light::Spot THIS;

void		THIS::init(parent_t * const & parent)
{
	setParent(parent);

	auto app = get_fnd_app();

	neb::fnd::core::light::base::init(parent);
	
	G::make_object<THIS, int>(app->_M_graphics_plugin, neb::fnd::plug::gfx::core::light::type::SPOT);
}
void		THIS::set_spot_direction(glm::vec3)
{
	abort();
}


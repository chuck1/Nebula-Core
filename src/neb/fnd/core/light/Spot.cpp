#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/core/light/Spot.hpp>
#include <neb/fnd/core/light/util/parent.hpp>

#include <neb/fnd/plug/gfx/core/light/util/decl.hpp>
#include <neb/fnd/plug/gfx/core/light/Base.hpp>

typedef neb::fnd::core::light::Spot THIS;

void		THIS::init(parent_t * const & parent)
{
	printv_func(DEBUG);

	setParent(parent);

	auto app = get_fnd_app();

	//neb::fnd::core::light::base::init(parent);

	if(G::has_object()) {
		printv(DEBUG, "plugin gfx not null");
	} else {
		G::make_object<THIS, int>(
				app->_M_graphics_plugin,
				neb::fnd::plug::gfx::core::light::type::SPOT);
	}
}
void		THIS::set_spot_direction(glm::vec3)
{
	abort();
}


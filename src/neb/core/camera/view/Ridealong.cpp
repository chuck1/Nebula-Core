#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/camera/view/Ridealong.hpp>
#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/plug/gfx/camera/view/util/decl.hpp>
#include <neb/fnd/plug/gfx/camera/view/Base.hpp>

typedef neb::fnd::camera::view::Ridealong THIS;

void		THIS::init(parent_t * const & parent)
{
	setParent(parent);

	auto app = get_fnd_app();

	G::make_object<THIS, int>(app->_M_graphics_plugin, neb::fnd::plug::gfx::camera::view::type::RIDEALONG);
}
void		THIS::step(gal::etc::timestep const & ts)
{
}


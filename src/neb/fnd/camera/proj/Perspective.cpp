#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/camera/proj/Perspective.hpp>

#include <neb/fnd/plug/gfx/camera/proj/util/decl.hpp>
#include <neb/fnd/plug/gfx/camera/proj/Base.hpp>

typedef neb::fnd::camera::proj::Perspective THIS;

THIS::Perspective()
{
}
void		THIS::init(parent_t * const & p)
{
	setParent(p);

	auto app = get_fnd_app();

	G::make_object<THIS, int>(app->get_graphics_plugin(), neb::fnd::plug::gfx::camera::proj::type::PERSPECTIVE);

	//if(G::has_object())
	G::get_object()->calculate();
}
void		THIS::step(gal::etc::timestep const & p)
{
}
void		THIS::release()
{
}




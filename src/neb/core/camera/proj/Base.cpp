#include <neb/fnd/camera/proj/Base.hpp>
#include <neb/fnd/plug/gfx/camera/proj/Base.hpp>

typedef neb::fnd::camera::proj::Base THIS;

void		THIS::load(neb::fnd::glsl::program::Base * const & p)
{
	if(G::has_object())
		G::get_object()->load(p);
}
glm::mat4		THIS::proj()
{
	if(G::has_object())
		return G::get_object()->proj();
	return glm::mat4();
}
void			THIS::calculate_geometry()
{
}



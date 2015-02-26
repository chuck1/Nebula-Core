#include <neb/fnd/camera/view/shadow/Directional.hpp>

typedef neb::fnd::camera::view::shadow::Directional THIS;

THIS::Directional()
{
}
glm::mat4			THIS::view()
{
	abort();
	return glm::mat4();
}
void				THIS::step(gal::etc::timestep const & ts)
{
}




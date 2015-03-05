#include <neb/fnd/camera/view/shadow/Spot.hpp>

typedef neb::fnd::camera::view::shadow::Spot THIS;

THIS::Spot()
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


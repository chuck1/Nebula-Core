#include <neb/fnd/camera/view/shadow/Point.hpp>

typedef neb::fnd::camera::view::shadow::Point THIS;

THIS::Point()
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


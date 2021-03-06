

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

//#include <PxPhysicsAPI.h>
//#include <gal/log/log.hpp>

#include <neb/fnd/util/debug.hpp>
#include <neb/fnd/input/js.hpp>
//#include <neb/phx/core/actor/rigidbody/base.hpp>

#include <neb/fnd/core/actor/control/rigidbody/Manual.hpp>
//#include <neb/phx/util/convert.hpp>

typedef neb::fnd::core::actor::control::rigidbody::Manual THIS;

THIS::~Manual()
{
}
void			THIS::step(gal::etc::timestep const & ts)
{
}
glm::vec3		THIS::f_body()
{
	printv_func(DEBUG);
	return f_ * 5.0f;
}
glm::vec3		THIS::t_body()
{
	printv_func(DEBUG);

	auto js = _M_js.lock();
	if(js) {
		return glm::vec3(
				js->get_axes(1),
				-js->get_axes(2),
				-js->get_axes(0));
	}
	else
		return t_ * 1.5f;
}
glm::vec3		THIS::f_global()
{
	printv_func(DEBUG);
	return glm::vec3();
}
glm::vec3		THIS::t_global()
{
	printv_func(DEBUG);
	return glm::vec3();
}




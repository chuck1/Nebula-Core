

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

//#include <PxPhysicsAPI.h>
//#include <gal/log/log.hpp>

#include <neb/fnd/util/debug.hpp>

//#include <neb/phx/core/actor/rigidbody/base.hpp>
//
#include <neb/fnd/core/actor/control/rigidbody/Base.hpp>
//#include <neb/phx/util/convert.hpp>

typedef neb::fnd::core::actor::control::rigidbody::base THIS;

THIS::base()
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
}
THIS::~base()
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
}
void		THIS::release()
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
}
void			THIS::connect(std::shared_ptr<neb::fnd::input::source> src)
{
	connectKeyFun(src, 20);
}
void			THIS::connect(std::shared_ptr<neb::fnd::input::js> src)
{
	connect_js_button_fun(src, 20);
}
void			THIS::serialize(boost::archive::polymorphic_iarchive & ar, unsigned int const & version)
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
	abort();
}
void			THIS::serialize(boost::archive::polymorphic_oarchive & ar, unsigned int const & version)
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
	abort();
}
int			THIS::keyFun(
		std::shared_ptr<neb::fnd::input::source> const & src,
		int key,
		int scancode,
		int action,
		int mods)
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);

/*	long unsigned int f = flag_.val_ & (
			neb::gfx::camera::view::util::flag::NORTH |
			neb::gfx::camera::view::util::flag::SOUTH |
			neb::gfx::camera::view::util::flag::EAST |
			neb::gfx::camera::view::util::flag::WEST |
			neb::gfx::camera::view::util::flag::UP |
			neb::gfx::camera::view::util::flag::DOWN);*/

	printv(DEBUG, "key = %i scancode = %i action = %i mods = %i flag = %i\n", key, scancode, action, mods);

	glm::vec3 x(1.0,0.0,0.0);
	glm::vec3 y(0.0,1.0,0.0);
	glm::vec3 z(0.0,0.0,1.0);
	
	int ret = 0;

	switch(action) {
		case GLFW_PRESS:
			switch(key) {
				case GLFW_KEY_D:
					f_ += x;
					ret = 1;
					break;
				case GLFW_KEY_A:
					f_ -= x;
					ret = 1;
					break;
				case GLFW_KEY_E:
					f_ += y;
					ret = 1;
					break;
				case GLFW_KEY_Q:
					f_ -= y;
					ret = 1;
					break;
				case GLFW_KEY_W:
					f_ -= z;
					ret = 1;
					break;
				case GLFW_KEY_S:
					f_ += z;
					ret = 1;
					break;
				case GLFW_KEY_I:
					t_ += x;
					ret = 1;
					break;
				case GLFW_KEY_K:
					t_ -= x;
					ret = 1;
					break;
				case GLFW_KEY_L:
					t_ -= y;
					ret = 1;
					break;
				case GLFW_KEY_J:
					t_ += y;
					ret = 1;
					break;
				case GLFW_KEY_O:
					t_ -= z;
					ret = 1;
					break;
				case GLFW_KEY_U:
					t_ += z;
					ret = 1;
					break;
				default:
					ret = 0;
					break;
			}
			break;
		case GLFW_RELEASE:
			switch(key) {
				case GLFW_KEY_D:
					f_ -= x;
					ret = 1;
					break;
				case GLFW_KEY_A:
					f_ += x;
					ret = 1;
					break;
				case GLFW_KEY_E:
					f_ -= y;
					ret = 1;
					break;
				case GLFW_KEY_Q:
					f_ += y;
					ret = 1;
					break;
				case GLFW_KEY_W:
					f_ += z;
					ret = 1;
					break;
				case GLFW_KEY_S:
					f_ -= z;
					ret = 1;
					break;
				case GLFW_KEY_I:
					t_ -= x;
					ret = 1;
					break;
				case GLFW_KEY_K:
					t_ += x;
					ret = 1;
					break;
				case GLFW_KEY_L:
					t_ += y;
					ret = 1;
					break;
				case GLFW_KEY_J:
					t_ -= y;
					ret = 1;
					break;
				case GLFW_KEY_O:
					t_ += z;
					ret = 1;
					break;
				case GLFW_KEY_U:
					t_ -= z;
					ret = 1;
					break;
				default:
					ret = 0;
					break;
			}
			break;
		default:
			printv(DEBUG, "action %i\n", action);
			break;
	}

	printv(DEBUG, "t = %16f %16f %16f\n", t_.x, t_.y, t_.z);
	printv(DEBUG, "f = %16f %16f %16f\n", f_.x, f_.y, f_.z);

	return ret;
}




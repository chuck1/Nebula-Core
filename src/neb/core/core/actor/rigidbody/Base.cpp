#include <neb/fnd/core/actor/rigidbody/Base.hpp>

#include <neb/fnd/plug/phx/core/actor/rigidbody/Base.hpp>

typedef neb::fnd::core::actor::rigidbody::base THIS;

glm::vec3		THIS::get_angular_velocity()
{
	
	auto p = P::get_object();

	auto rb = std::dynamic_pointer_cast<neb::fnd::plug::phx::core::actor::rigidbody::Base>(p);

	return rb->get_angular_velocity();
}


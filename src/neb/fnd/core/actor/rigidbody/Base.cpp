#include <neb/fnd/core/actor/control/rigidbody/Manual.hpp>
#include <neb/fnd/core/actor/control/rigidbody/PD.hpp>

#include <neb/fnd/core/actor/rigidbody/Base.hpp>

#include <neb/fnd/plug/phx/core/actor/rigidbody/Base.hpp>

typedef neb::fnd::core::actor::rigidbody::base THIS;

glm::vec3		THIS::get_angular_velocity()
{
	auto p = P::get_object();

	auto rb = std::dynamic_pointer_cast<neb::fnd::plug::phx::core::actor::rigidbody::Base>(p);

	return rb->get_angular_velocity();
}
glm::vec3		THIS::get_mass_space_inertia_tensor()
{
	auto p = P::get_object();

	auto rb = std::dynamic_pointer_cast<neb::fnd::plug::phx::core::actor::rigidbody::Base>(p);

	return rb->get_mass_space_inertia_tensor();
}
THIS::W_C			THIS::createControlManual(
		std::shared_ptr<neb::fnd::input::source> src)
{
	//void			neb::phx::core::actor::rigidbody::base::createControlManual(std::shared_ptr<neb::fnd::input::source> src)

	printv_func(DEBUG);
	//neb::phx::core::actor::rigidbody::base::createControlManual(window);
	
	//typedef neb::phx::core::actor::control::rigidbody::manual Control;
	typedef neb::fnd::core::actor::control::rigidbody::Manual CONTROL;

	CONTROL* pc = new CONTROL();
	std::shared_ptr<CONTROL> control(pc);

	control_ = control;

	control->actor_ = is_fnd_actor_rigidbody_base();//isPxActorRigidBodyBase();
	
	control->connectKeyFun(src, 20);

	return control;
}
THIS::W_C			THIS::createControlPD()
{
	printv_func(DEBUG);
	
/*	auto self = std::dynamic_pointer_cast<neb::phx::core::actor::rigidbody::base>(
			shared_from_this()
			);
*/	
	auto self = is_fnd_actor_rigidbody_base();
	
	typedef neb::fnd::core::actor::control::rigidbody::PD T;

	T* p = new T();
	std::shared_ptr<T> control(p);
	
	control_ = control;
	
	control->actor_ = self;
	
	control->p_target_ = glm::vec3(0,0,5);
	
	control->q_target_ = glm::angleAxis(1.5f, glm::vec3(0.0,1.0,0.0));

	return control;
}



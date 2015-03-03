
#include <gal/stl/verbosity.hpp>

#include <neb/fnd/app/Base.hpp>

#include <neb/fnd/plug/gfx/core/actor/util/decl.hpp>
#include <neb/fnd/plug/gfx/core/actor/Base.hpp>

#include <neb/fnd/plug/phx/core/actor/util/decl.hpp>
#include <neb/fnd/plug/phx/core/actor/Base.hpp>

#include <neb/fnd/core/actor/control/rigidbody/Manual.hpp>
#include <neb/fnd/core/actor/control/rigidbody/PD.hpp>

//#include <neb/phx/core/actor/control/rigidbody/base.hpp>

#include <neb/fnd/core/actor/rigiddynamic/Base.hpp>

typedef neb::fnd::core::actor::rigiddynamic::base THIS;

THIS::base()
{
}
THIS::~base() 
{
	printv_func(DEBUG);
}
void			THIS::init(parent_t * const & p)
{
	printv_func(DEBUG);

	setParent(p);

	auto app = get_fnd_app();

	if(!G::has_object())
		G::make_object<THIS, int>(
				app->_M_graphics_plugin,
				neb::fnd::plug::gfx::core::actor::type::RIGIDDYNAMIC);

	if(!P::has_object())
		P::make_object<THIS, int>(
				app->_M_physics_plugin,
				neb::fnd::plug::phx::core::actor::type::RIGIDDYNAMIC);

	neb::fnd::core::actor::base::init(p);

	//neb::phx::core::actor::base::init(p);
	//neb::phx::core::actor::actor::base::init();
	//neb::phx::core::actor::rigidactor::base::init();
	//neb::phx::core::actor::rigidbody::base::init();
	//neb::phx::core::actor::rigiddynamic::base::init();

	//neb::gfx::core::actor::base::init(p);

	//neb::fin::core::actor::base::init(p);
	//neb::fin::core::actor::rigidactor::base::init();
}
void					THIS::release()
{
	printv_func(DEBUG);

	neb::fnd::core::actor::base::release();

	//neb::phx::core::actor::base::release();
	//neb::phx::core::actor::actor::base::release();
	//neb::phx::core::actor::rigidactor::base::release();
	//neb::phx::core::actor::rigidbody::base::release();
	//neb::phx::core::actor::rigiddynamic::base::release();

	//neb::gfx::core::actor::base::release();

	//neb::fin::core::actor::base::release();
}
void					THIS::step(
		gal::etc::timestep const & ts)
{
	printv_func(DEBUG);

	neb::fnd::core::actor::base::step(ts);

	//neb::phx::core::actor::base::step(ts);
	//neb::phx::core::actor::actor::base::step(ts);
	//neb::phx::core::actor::rigidactor::base::step(ts);
	//neb::phx::core::actor::rigidbody::base::step(ts);
	//neb::phx::core::actor::rigiddynamic::base::step(ts);

	//neb::gfx::core::actor::base::step(ts);

	//neb::fin::core::actor::base::step(ts);

}
void				THIS::createControlManual(
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

/*	control->conn_.key_fun_ = window->sig_.key_fun_.connect(
			20,
			neb::gfx::window::signals::KeyFun::slot_type(
				&neb::phx::core::actor::control::rigidbody::base::key_fun,
				control.get(),
				_1,
				_2,
				_3,
				_4,
				_5
				).track_foreign(control)
			);
*/

}
void			THIS::createControlPD()
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

}



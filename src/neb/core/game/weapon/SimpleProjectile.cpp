
#include <gal/log/log.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <neb/core/timer/actor/Release.hpp>

//#include <neb/gfx/window/Base.hh>

#include <neb/core/util/debug.hpp>
#include <neb/core/util/log.hpp>

#include <neb/core/app/Base.hpp>
/*#include <neb/phx/filter.hpp>
#include <neb/phx/core/actor/rigiddynamic/base.hpp>
#include <neb/phx/core/scene/base.hpp>
#include <neb/phx/core/shape/box.hpp>
*/
#include <neb/core/util/log.hpp>
#include <neb/core/core/scene/base.hpp>
#include <neb/core/core/actor/base.hpp>
#include <neb/core/game/weapon/SimpleProjectile.hpp>

typedef neb::fnd::game::weapon::SimpleProjectile THIS;

THIS::SimpleProjectile()
{
}
void			THIS::connect(
		std::shared_ptr<neb::fnd::input::source> src)
{
	LOG(lg, neb::fnd::sl, debug) << __PRETTY_FUNCTION__;;
	connectKeyFun(src, 20);
}
int			THIS::key_fun(
		std::shared_ptr<neb::fnd::input::source> src,
		int key,
		int,
		int action,
		int mods)
{
	LOG(lg, neb::fnd::sl, debug) << __PRETTY_FUNCTION__;;

	int key_fire = GLFW_KEY_SPACE;

	switch(action) {
		case GLFW_PRESS:
			if(key == key_fire) {
				fire();
				return 1;
			}
			break;
	}

	return 0;
}
void			THIS::fire()
{
	LOG(lg, neb::fnd::sl, debug) << __PRETTY_FUNCTION__;;
	
	//auto app(neb::fnd::app::Base::global());
	auto app = get_fnd_app();

	if((app->ts_.time - last_) < cooldown_) return;
	last_ = app->ts_.time;
	
	// create projectile actor

	auto actor = dynamic_cast<neb::fnd::core::actor::base*>(getParent());
	assert(actor);

	auto scene = dynamic_cast<neb::fnd::core::scene::base*>(actor->getScene());

	auto proj_base = scene->createActorRigidDynamicUninitialized().lock();

	//auto proj = std::dynamic_pointer_cast<neb::phx::core::actor::rigiddynamic::base>(proj_base);
	auto proj = proj_base;
	assert(proj);

	proj->simulation_.word0 = neb::phx::filter::filter::type::DYNAMIC | neb::phx::filter::filter::type::PROJECTILE;
	proj->simulation_.word1 = neb::phx::filter::filter::RIGID_AGAINST;
	proj->simulation_.word2 = neb::phx::filter::filter::type::PROJECTILE;
	proj->simulation_.word3 = neb::phx::filter::filter::PROJECTILE_AGAINST;


	// initialize position and velocity

	// relative values

	glm::vec3 pos_relative(0,0,-2);
	
	glm::vec3 vel_relative(0,0,-1);
	vel_relative *= velocity_;

	// rotate relative values to actor's space
	pos_relative = actor->pose_.rot_ * pos_relative;
	vel_relative = actor->pose_.rot_ * vel_relative;

	// center on actor
	proj->pose_ = actor->pose_;

	// translate

	proj->pose_.pos_ += pos_relative;

	// velocity

	proj->velocity_ = vel_relative;
/*
	auto rigidbody(actor->isPxActorRigidBodyBase());
	if(rigidbody) {
		proj->velocity_ += rigidbody->velocity_;
	}
	*/
	
	proj->velocity_ += actor->velocity_;

	proj->init(scene);

	// shape
	auto shape = proj->createShapeCuboid(
			neb::fnd::core::shape::cuboid::Desc(glm::vec3(size_))
			);

	proj->init(scene);
	//proj->setupFiltering();

	// release timer
	auto t = std::make_shared<neb::fnd::timer::actor::Release>(proj, scene->last_ + 5.0);

	LOG(lg, neb::fnd::sl, debug) << t.use_count();
	
	t->activate();

	LOG(lg, neb::fnd::sl, debug) << t.use_count();
}


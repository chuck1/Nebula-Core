
#include <gal/log/log.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <neb/fnd/timer/actor/Release.hpp>

//#include <neb/gfx/window/Base.hh>

#include <neb/fnd/util/debug.hpp>
#include <neb/fnd/util/log.hpp>

#include <neb/fnd/app/Base.hpp>
/*#include <neb/phx/filter.hpp>
#include <neb/phx/core/actor/rigiddynamic/base.hpp>
#include <neb/phx/core/scene/base.hpp>
#include <neb/phx/core/shape/box.hpp>
*/
#include <neb/fnd/util/log.hpp>
#include <neb/fnd/core/scene/Base.hpp>
#include <neb/fnd/core/actor/Base.hpp>
#include <neb/fnd/game/weapon/SimpleProjectile.hpp>

typedef neb::fnd::game::weapon::SimpleProjectile THIS;

THIS::SimpleProjectile()
{
}
void			THIS::connect(
		std::shared_ptr<neb::fnd::input::source> src)
{
	printv(info, "%s\n", __PRETTY_FUNCTION__);
	connectKeyFun(src, 20);
}
int			THIS::keyFun(
		std::shared_ptr<neb::fnd::input::source> src,
		int key,
		int,
		int action,
		int mods)
{
	printv(info, "%s\n", __PRETTY_FUNCTION__);

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
	printv(info, "%s\n", __PRETTY_FUNCTION__);
	
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


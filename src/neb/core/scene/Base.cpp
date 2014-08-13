
#include <stdio.h>

#include <gal/log/log.hpp>

#include <neb/core/debug.hh>
#include <neb/core/actor/base.hpp>
#include <neb/core/actor/util/Type.hh>
#include <neb/core/light/base.hpp>
#include <neb/core/light/util/light_count.hpp>
#include <neb/core/shape/base.hpp>
#include <neb/core/scene/base.hpp>
#include <neb/core/scene/util/decl.hpp>
#include <neb/core/scene/util/Parent.hh>
#include <neb/core/util/config.hpp>
#include <neb/core/util/log.hpp>

using namespace std;

neb::core::core::scene::base::base(sp::shared_ptr<neb::core::core::scene::util::parent> parent):
	parent_(parent)
{
	if(DEBUG_NEB) LOG(lg, neb::core::scene::sl, debug) << __FUNCSIG__;
}
neb::core::core::scene::base::~base() {
	if(DEBUG_NEB) LOG(lg, neb::core::scene::sl, debug) << __FUNCSIG__;
}
void neb::core::core::scene::base::init() {
	if(DEBUG_NEB) LOG(lg, neb::core::scene::sl, debug) << __FUNCSIG__;
}
void neb::core::core::scene::base::release() {
	if(DEBUG_NEB) LOG(lg, neb::core::scene::sl, debug) << __FUNCSIG__;
	
	neb::core::actor::util::parent::clear();
}
neb::core::pose						neb::core::core::scene::base::getPose() {
	return neb::core::pose();
}		
neb::core::pose						neb::core::core::scene::base::getPoseGlobal() {
	return neb::core::pose();
}
weak_ptr<neb::core::core::scene::util::parent>		neb::core::core::scene::base::getParent() {
	return parent_;
}
void						neb::core::core::scene::base::add_deferred(sp::shared_ptr<neb::core::actor::base> actor) {

	actors_deferred_[actor->name_] = actor;
}
void		neb::core::core::scene::base::step(gal::std::timestep const & ts) {

	typedef neb::core::actor::util::parent A;

	A::map_.for_each<0>([&] (A::map_type::iterator<0> it) {
			auto actor = sp::dynamic_pointer_cast<neb::core::actor::base>(it->ptr_);
			assert(actor);
			actor->step(ts);
			});

}
/*weak_ptr<neb::core::actor::base>		neb::core::core::scene::base::createActorRigidStaticCube(neb::core::pose const & pose, double size) {

	auto actor = createActorRigidStaticUninitialized().lock();

	// set data members

	actor->pose_ = pose;

	// initialize (create physx)

	actor->init();

	// create shape

	auto shape = actor->createShapeCube(size);

	// reinitialize in order to apply filtering to shape
	/// @todo consider implementing refresh-type function instead
	actor->init();

	return actor;
}*/
/*sp::weak_ptr<neb::core::actor::base>		neb::core::core::scene::base::createActorRigidDynamicCube(neb::core::pose const & pose, double size) {

	auto actor = createActorRigidDynamicUninitialized().lock();

	// set data members

	actor->pose_ = pose;

	// initialize (create physx)

	actor->init();

	// create shape

	auto shape = actor->createShapeCube(size);

	// reinitialize in order to apply filtering to shape
	/// @todo consider implementing refresh-type function instead
	actor->init();

	return actor;
}*/
weak_ptr<neb::core::actor::base>		neb::core::core::scene::base::createActorLightPoint(vec3 p) {

	// actor
	auto actor = createActorBase(neb::core::pose(p)).lock();

	// shape	
	auto shape = actor->createShapeBase(neb::core::pose()).lock();

	// light
	auto light = shape->createLightPoint();

	return actor;	
}




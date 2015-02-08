
#include <stdio.h>

#include <gal/log/log.hpp>

#include <neb/core/util/debug.hpp>
#include <neb/core/util/config.hpp>
#include <neb/core/util/log.hpp>
#include <neb/core/core/actor/base.hpp>
#include <neb/core/core/actor/rigidbody/desc.hpp>
#include <neb/core/core/actor/util/decl.hpp>
#include <neb/core/core/light/base.hpp>
#include <neb/core/core/light/util/light_count.hpp>
#include <neb/core/core/shape/base.hpp>
#include <neb/core/core/scene/base.hpp>
#include <neb/core/core/scene/util/decl.hpp>
#include <neb/core/core/scene/util/parent.hpp>

using namespace std;

typedef neb::fnd::core::scene::base THIS;

THIS::base():
	last_(0)
{
	LOG(lg, neb::fnd::core::scene::sl, debug) << __FUNCSIG__;
}
THIS::~base()
{
	LOG(lg, neb::fnd::core::scene::sl, debug) << __FUNCSIG__;
}
void			THIS::__init(parent_t * const & p)
{
	LOG(lg, neb::fnd::core::scene::sl, debug) << __FUNCSIG__;

	neb::fnd::core::actor::util::parent::initChildren(this);
}
void			THIS::__release()
{
	LOG(lg, neb::fnd::core::scene::sl, debug) << __FUNCSIG__;
	
	neb::fnd::core::actor::util::parent::clear();
}
neb::fnd::math::pose						THIS::getPose() const {
	return neb::fnd::math::pose();
}		
neb::fnd::math::pose						THIS::getPoseGlobal() const {
	return neb::fnd::math::pose();
}
void						THIS::add_deferred(std::shared_ptr<neb::fnd::core::actor::base> actor) {
	/** @todo deprecated */
	abort();
	//actors_deferred_[actor->name_] = actor;
}
void		THIS::step(gal::etc::timestep const & ts) {

	actors::step(ts);

//	A::map_.for_each([&] (A::map_type::pointer p) {
//			auto actor = std::dynamic_pointer_cast<neb::fnd::core::actor::base>(it->ptr_);
//			assert(actor);
//			actor->step(ts);
//			});

}
weak_ptr<neb::fnd::core::actor::base>		THIS::createActorRigidStaticCube(
		neb::fnd::math::pose pose,
		double size) {

	auto actor = createActorRigidStaticUninitialized().lock();
	actor->pose_ = pose;
	actor->init(this);

	// create shape

	auto shape = actor->createShapeCube(neb::fnd::math::pose(), size);

	// reinitialize in order to apply filtering to shape
	/// @todo consider implementing refresh-type function instead
	actor->init(this);

	return actor;
}
weak_ptr<neb::fnd::core::actor::base>		THIS::createActorRigidStaticCuboid(
		neb::fnd::math::pose pose,
		glm::vec3 size) {

	auto actor = createActorRigidStaticUninitialized().lock();
	actor->pose_ = pose;
	actor->init(this);
	
	// create shape
	
	auto shape = actor->createShapeCuboid(neb::fnd::core::shape::cuboid::Desc(size));

	// reinitialize in order to apply filtering to shape
	/// @todo consider implementing refresh-type function instead
	actor->init(this);

	return actor;
}
weak_ptr<neb::fnd::core::actor::base>		THIS::createActorRigidDynamicCuboid(
		neb::fnd::core::actor::rigidbody::desc const &		actor_desc,
		neb::fnd::core::shape::cuboid::Desc const &		shape_desc)
{

	auto actor = createActorRigidDynamicUninitialized().lock();

	actor->pose_ = actor_desc.pose;

	actor->init(this);

	// shape
	auto shape = actor->createShapeCuboid(shape_desc);

	/// @todo consider implementing refresh-type function instead
	actor->init(this);

	return actor;
}
weak_ptr<neb::fnd::core::actor::base>		THIS::createActorLightPoint(glm::vec3 p) {

	// actor
	auto actor = createActorBase(neb::fnd::math::pose(p)).lock();

	// shape	
	auto shape = actor->createShapeBase(neb::fnd::math::pose()).lock();

	// light
	auto light = shape->createLightPoint();

	return actor;	
}
std::weak_ptr<neb::fnd::core::actor::base>		THIS::createActorLightDirectional(glm::vec3 p)
{
	auto actor = createActorBase(neb::fnd::math::pose()).lock();

	auto shape = actor->createShapeBase(neb::fnd::math::pose()).lock();

	auto light = shape->createLightDirectional(p);

	return actor;	
}
std::weak_ptr<neb::fnd::core::actor::base>		THIS::createActor(
		neb::fnd::core::actor::desc const * const & desc
		)
{
	assert(desc);
	return desc->visit(this);
}
void			THIS::addActor(
		std::shared_ptr<neb::fnd::core::actor::base> const & actor
		)
{
	insert(actor);
	actor->init(this);
}
void			THIS::load(
		boost::archive::polymorphic_iarchive & ar,
		unsigned int const & version)
{
	ar & boost::serialization::make_nvp("flag",flag_);
	ar & boost::serialization::make_nvp("actors",neb::fnd::core::actor::util::parent::map_);
}
void			THIS::save(
		boost::archive::polymorphic_oarchive & ar,
		unsigned int const & version) const
{
	ar & boost::serialization::make_nvp("flag",flag_);
	ar & boost::serialization::make_nvp("actors",neb::fnd::core::actor::util::parent::map_);
}




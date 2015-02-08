#include <glm/gtx/transform.hpp>

#include <gal/stl/map.hpp>

#include <gal/log/log.hpp>

#include <neb/core/math/geo/polygon.hpp>
#include <neb/core/util/config.hpp>
#include <neb/core/util/log.hpp>
#include <neb/core/util/debug.hpp>
#include <neb/core/core/actor/base.hpp>
#include <neb/core/core/shape/base.hpp>
#include <neb/core/core/light/base.hpp>

typedef neb::fnd::core::shape::base THIS;

THIS::base():
	scale_(1.0)
{
	LOG(lg, neb::fnd::core::shape::sl, debug) << __FUNCSIG__;
}
THIS::~base()
{
	LOG(lg, neb::fnd::core::shape::sl, info) << __FUNCSIG__;
}

bool							THIS::hasScene()
{
	if(!hasParent()) return false;

	auto shape = dynamic_cast<THIS*>(getParent());
	
	if(shape) return shape->hasScene();

	auto actor = dynamic_cast<neb::fnd::core::actor::base*>(getParent());

	assert(actor);
	
	return actor->hasScene();
}

neb::fnd::core::scene::base*				THIS::getScene()
{
	auto shape = dynamic_cast<THIS*>(getParent());
	
	if(shape) return shape->getScene();

	auto actor = dynamic_cast<neb::fnd::core::actor::base*>(getParent());

	assert(actor);
	
	return actor->getScene();
}


neb::fnd::math::pose				THIS::getPoseGlobal() const {
	LOG(lg, neb::fnd::core::shape::sl, debug) << __FUNCSIG__;
	
	return getParent()->getPoseGlobal() * pose_;
}
neb::fnd::math::pose				THIS::getPose() const {
	return pose_;
}
void					THIS::__callbackPose(neb::fnd::math::pose const & gpose) {
	auto pose = gpose * pose_;
	neb::fnd::core::shape::util::parent::callbackPose(pose);
	neb::fnd::core::light::util::parent::callbackPose(pose);
}
void					THIS::init(neb::fnd::core::shape::util::parent * const & p)
{
	LOG(lg, neb::fnd::core::shape::sl, debug) << __FUNCSIG__;
	
	setParent(p);
	
	//auto me = std::dynamic_pointer_cast<THIS>(shared_from_this());

	//auto scene = get_parent()->get_scene();

	// type

	// program
	/*	if(image_.length() == 0) {
		program_ = neb::program_name::LIGHT;
		} else {
	 ** @todo replace this with something better... *
	//flag_.set(neb::fnd::core::shape::flag::e::IMAGE);

	program_ = neb::program_name::IMAGE;
	}
	*/

	neb::fnd::core::shape::util::parent::initChildren(this);
	neb::fnd::core::light::util::parent::initChildren(this);

}
void					THIS::release()
{
	LOG(lg, neb::fnd::core::shape::sl, debug) << __FUNCSIG__;

	neb::fnd::core::shape::util::parent::map_.clear();
	neb::fnd::core::light::util::parent::map_.clear();
}
void						THIS::step(
		gal::etc::timestep const & ts)
{
	neb::fnd::core::shape::util::parent::step(ts);
	neb::fnd::core::light::util::parent::step(ts);
}
void	THIS::load(ba::polymorphic_iarchive & ar, unsigned int const & v)
{
	LOG(lg, neb::fnd::core::shape::sl, debug) << __FUNCSIG__;
	__serialize(ar, v);
}
void	THIS::save(ba::polymorphic_oarchive & ar, unsigned int const & v) const
{
	LOG(lg, neb::fnd::core::shape::sl, debug) << __FUNCSIG__;
	const_cast<THIS*>(this)->__serialize(ar, v);
}








#include <gal/log/log.hpp>

#include <neb/fnd/util/config.hpp>
#include <neb/fnd/util/log.hpp>
#include <neb/fnd/util/debug.hpp>
#include <neb/fnd/core/light/util/parent.hpp>
#include <neb/fnd/core/shape/base.hpp>
#include <neb/fnd/core/light/base.hpp>

typedef neb::fnd::core::light::base THIS;

THIS::base()
{
}
neb::fnd::math::pose		THIS::getPose() {
	LOG(lg, neb::fnd::core::light::sl, debug) << __FUNCSIG__;
	
	return pose_;
}
neb::fnd::math::pose		THIS::getPoseGlobal()
{
	LOG(lg, neb::fnd::core::light::sl, debug) << __FUNCSIG__;
	
	auto p = getParent()->getPoseGlobal() * pose_;
	
	return p;
}
glm::vec4			THIS::getPos() {
	return glm::vec4(pose_.pos_, 1.0);
}
bool				THIS::hasScene() const
{
	if(!hasParent()) return false;

	auto shape = dynamic_cast<neb::fnd::core::shape::base*>(getParent());
	
	assert(shape);
	
	return shape->hasScene();
}
neb::fnd::core::scene::base*	THIS::getScene()
{
	auto shape = dynamic_cast<neb::fnd::core::shape::base*>(getParent());
	
	assert(shape);
	
	return shape->getScene();
}
void		THIS::load(
		boost::archive::polymorphic_iarchive & ar,
		unsigned int const & version)
{
	serializeTemplate(ar, version);
	ar & BOOST_SERIALIZATION_NVP(pose_);
}
void		THIS::save(
		boost::archive::polymorphic_oarchive & ar,
		unsigned int const & version) const
{
	const_cast<THIS*>(this)->serializeTemplate(ar, version);
	ar & BOOST_SERIALIZATION_NVP(pose_);
}




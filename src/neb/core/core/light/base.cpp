
#include <gal/log/log.hpp>

#include <neb/core/util/config.hpp>
#include <neb/core/util/log.hpp>
#include <neb/core/util/debug.hpp>
#include <neb/core/core/light/util/parent.hpp>
#include <neb/core/core/shape/base.hpp>
#include <neb/core/core/light/base.hpp>

neb::core::core::light::base::base()
{
}
neb::core::pose			neb::core::core::light::base::getPose() {
	LOG(lg, neb::core::core::light::sl, debug) << __FUNCSIG__;
	
	return pose_;
}
neb::core::pose			neb::core::core::light::base::getPoseGlobal()
{
	LOG(lg, neb::core::core::light::sl, debug) << __FUNCSIG__;
	
	auto p = getParent()->getPoseGlobal() * pose_;
	
	return p;
}
glm::vec4			neb::core::core::light::base::getPos() {
	return glm::vec4(pose_.pos_, 1.0);
}
bool				neb::core::core::light::base::hasScene() const
{
	if(!hasParent()) return false;

	auto shape = dynamic_cast<neb::core::core::shape::base*>(getParent());
	
	assert(shape);
	
	return shape->hasScene();
}
neb::core::core::scene::base*	neb::core::core::light::base::getScene()
{
	
	auto shape = dynamic_cast<neb::core::core::shape::base*>(getParent());
	
	assert(shape);
	
	return shape->getScene();
}



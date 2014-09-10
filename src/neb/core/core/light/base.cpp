
#include <gal/log/log.hpp>

#include <neb/core/util/config.hpp>
#include <neb/core/util/log.hpp>
#include <neb/core/util/debug.hpp>
#include <neb/core/core/light/util/parent.hpp>
#include <neb/core/core/light/base.hpp>

neb::core::core::light::base::base(std::shared_ptr<neb::core::core::light::util::parent> parent):
	parent_(parent)
	//pos_(glm::vec4(0.0, 0.0, 0.0, 1.0))
{}
void				neb::core::core::light::base::init() {
	LOG(lg, neb::core::core::light::sl, debug) << __FUNCSIG__;

}
void				neb::core::core::light::base::release() {
	LOG(lg, neb::core::core::light::sl, debug) << __FUNCSIG__;
}
void				neb::core::core::light::base::step(gal::etc::timestep const & ts) {

}
neb::core::pose			neb::core::core::light::base::getPose() {
	LOG(lg, neb::core::core::light::sl, debug) << __FUNCSIG__;
	
	return pose_;
}
neb::core::pose			neb::core::core::light::base::getPoseGlobal() {
	LOG(lg, neb::core::core::light::sl, debug) << __FUNCSIG__;
	
	auto parent(parent_.lock());
	assert(parent);
	
	auto p = parent->getPoseGlobal() * pose_;
	
	return p;
}
glm::vec4			neb::core::core::light::base::getPos() {
	return glm::vec4(pose_.pos_, 1.0);
}
bool				neb::core::core::light::base::hasScene() const
{
	/** @todo deprecated */
	auto parent = parent_.lock();
	assert(parent);
	
	return parent->hasScene();
}
neb::core::core::scene::base*	neb::core::core::light::base::getScene()
{
	auto parent = parent_.lock();
	assert(parent);
	
//	auto p2 = std::dynamic_pointer_cast<neb::core::core::scene::base>(
//			parent->getScene().lock()
//			);

//	assert(p2);
//	return p2.get();
	return parent->getScene().lock().get();
}




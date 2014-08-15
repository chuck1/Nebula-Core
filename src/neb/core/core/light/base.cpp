
#include <gal/log/log.hpp>

#include <neb/core/util/config.hpp>
#include <neb/core/util/log.hpp>
#include <neb/core/util/debug.hpp>
#include <neb/core/core/light/util/parent.hpp>
#include <neb/core/core/light/base.hpp>

neb::core::light::base::base(sp::shared_ptr<neb::core::light::util::parent> parent):
	parent_(parent),
	pos_(glm::vec4(0.0, 0.0, 0.0, 1.0))
{}
void				neb::core::light::base::init() {
	LOG(lg, neb::core::light::sl, debug) << __FUNCSIG__;

}
void				neb::core::light::base::release() {
	LOG(lg, neb::core::light::sl, debug) << __FUNCSIG__;
}
void				neb::core::light::base::step(gal::std::timestep const & ts) {

}
neb::core::pose			neb::core::light::base::getPose() {
	LOG(lg, neb::core::light::sl, debug) << __FUNCSIG__;
	
	auto parent(parent_.lock());
	assert(parent);
	
	auto p = parent->getPoseGlobal();
	
	return p;
}
glm::vec4				neb::core::light::base::getPos() {
	return glm::vec4(pos_, 1.0);
}





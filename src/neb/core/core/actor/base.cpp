
#include <gal/log/log.hpp>

#include <neb/core/util/log.hpp>
#include <neb/core/util/config.hpp>
#include <neb/core/debug.hh>
#include <neb/core/actor/base.hpp>
#include <neb/core/actor/util/Types.hh>
#include <neb/core/scene/base.hpp>
#include <neb/core/util/decl.hpp>

/** @file base
 */

using namespace std;

neb::core::actor::base::base(sp::shared_ptr<neb::core::actor::util::parent> parent):
	density_(10.0),
	parent_(parent)
{
	if(DEBUG_NEB) LOG(lg, neb::core::actor::sl, debug) << __FUNCSIG__;
	assert(parent);
}
neb::core::actor::base::~base() {
	if(DEBUG_NEB) LOG(lg, neb::core::actor::sl, debug) << __FUNCSIG__;
}
void		neb::core::actor::base::init() {
}
void		neb::core::actor::base::release() {
	
	gal::std::__release::release();
	
	neb::core::actor::util::parent::clear();
	neb::core::shape::util::parent::clear();

}
sp::shared_ptr<neb::core::actor::util::parent>	neb::core::actor::base::get_parent() {
	auto parent(parent_.lock());
	assert(parent);
	return parent;
}
neb::core::pose				neb::core::actor::base::getPose() {
	return pose_;
}
neb::core::pose				neb::core::actor::base::getPoseGlobal() {
	if(DEBUG_NEB) LOG(lg, neb::core::actor::sl, debug) << __FUNCSIG__;
	
	neb::core::pose p;
	
	auto parent(parent_.lock());
	
	if(!parent) {
		p = parent->getPoseGlobal() * getPose();
	} else {
		p = getPose();
	}

	return p;
}
void		neb::core::actor::base::setPose(neb::core::pose const & pose) {
	pose_ = pose;
	
	flag_.set(neb::core::actor::util::flag::E::SHOULD_UPDATE);
}
void		neb::core::actor::base::step(gal::std::timestep const & ts) {
	if(DEBUG_NEB) LOG(lg, neb::core::actor::sl, debug) << __FUNCSIG__;

	typedef neb::core::actor::util::parent A;
	typedef neb::core::shape::util::parent S;

	A::map_.for_each<0>([&] (A::map_type::iterator<0> it) {
			it->ptr_->step(ts);
			});

	S::map_.for_each<0>([&] (S::map_type::iterator<0> it) {
			it->ptr_->step(ts);
			});

}
weak_ptr<neb::core::shape::base>			neb::core::actor::base::createShapeCube(neb::core::pose pose, double size) {
	
	auto shape = createShapeBox(pose, vec3(size));

	return shape;
	
}











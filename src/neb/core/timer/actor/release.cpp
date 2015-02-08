#include <gal/log/log.hpp>

#include <neb/core/timer/actor/Release.hpp>
#include <neb/core/core/actor/base.hpp>
#include <neb/core/util/debug.hpp>
#include <neb/core/util/log.hpp>

typedef neb::fnd::timer::actor::Release THIS;

THIS::Release(
		shared_ptr<neb::fnd::core::actor::base> actor, double seconds):
	neb::fnd::timer::actor::Base::Base(actor, seconds)
{
	LOG(lg, neb::fnd::sl, debug) << __PRETTY_FUNCTION__;
}
void		THIS::doSomething() {
	
	LOG(lg, neb::fnd::sl, debug) << __PRETTY_FUNCTION__;
	
	auto actor(actor_.lock());
	
	// actor was released after timer start
	if(!actor) return;
	
	neb::fnd::core::actor::base::parent_t * const & p = actor->getParent();
	
	p->erase(actor->_M_index);
}




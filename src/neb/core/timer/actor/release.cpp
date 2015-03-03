#include <gal/log/log.hpp>

#include <neb/fnd/timer/actor/Release.hpp>
#include <neb/fnd/core/actor/Base.hpp>
#include <neb/fnd/util/debug.hpp>

typedef neb::fnd::timer::actor::Release THIS;

THIS::Release(
		shared_ptr<neb::fnd::core::actor::base> actor, double seconds):
	neb::fnd::timer::Base::Base(seconds),
	neb::fnd::timer::actor::Base(actor, seconds)
{
	printv_func(DEBUG);
}
void		THIS::doSomething()
{
	printv_func(DEBUG);
	
	auto actor(actor_.lock());
	
	// actor was released after timer start
	if(!actor) return;
	
	neb::fnd::core::actor::base::parent_t * const & p = actor->getParent();
	
	p->erase(actor->_M_index);
}




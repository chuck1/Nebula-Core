#include <neb/core/util/log.hpp>
#include <neb/core/timer/Base.hpp>

typedef neb::fnd::timer::Base THIS;

void		THIS::activate()
{
	LOG(lg, neb::fnd::sl, debug) << __PRETTY_FUNCTION__;
	
	auto me = std::dynamic_pointer_cast<THIS>(shared_from_this());
	
	timer_->async_wait(boost::bind(&neb::fnd::timer::Base::doSomething, me));
}


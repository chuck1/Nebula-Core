#include <neb/fnd/timer/Base.hpp>

typedef neb::fnd::timer::Base THIS;

void		THIS::activate()
{
	printv_func(DEBUG);
	
	auto me = std::dynamic_pointer_cast<THIS>(shared_from_this());
	
	timer_->async_wait(boost::bind(&neb::fnd::timer::Base::doSomething, me));
}
void		THIS::step(gal::etc::timestep const & ts)
{
}


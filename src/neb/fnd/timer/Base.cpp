#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/timer/Base.hpp>

typedef neb::fnd::timer::Base THIS;

THIS::Base(double time):
	time_(time)
{
}
void		THIS::init(parent_t * const & p)
{
	setParent(p);
}
void		THIS::activate()
{
	printv_func(DEBUG);




	auto app = getParent();
	assert(app);

	timer_ = new boost::asio::deadline_timer(
			*app->_M_ios,
			boost::posix_time::seconds(time_));

	assert(!app->_M_ios->stopped());

	//auto app = std::dynamic_pointer_cast<neb::fnd::app::Base>(getParent());

	app->_M_ios->stopped();


	auto me = std::dynamic_pointer_cast<THIS>(shared_from_this());
	
	timer_->async_wait(boost::bind(&neb::fnd::timer::Base::doSomething, me));
}
void		THIS::step(gal::etc::timestep const & ts)
{
}


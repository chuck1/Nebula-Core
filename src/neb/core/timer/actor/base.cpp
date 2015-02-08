#include <gal/log/log.hpp>

#include <neb/core/timer/actor/Base.hpp>
#include <neb/core/core/actor/base.hpp>
#include <neb/core/util/debug.hpp>
#include <neb/core/util/log.hpp>

#include <neb/core/app/Base.hpp>

typedef neb::core::timer::actor::Base THIS;

THIS::Base(
		std::shared_ptr<neb::core::core::actor::base> actor,
		double seconds):
	actor_(actor)
{
	LOG(lg, neb::core::sl, debug) << __PRETTY_FUNCTION__;
	
	auto app = getParent();
	assert(app);

	timer_ = new boost::asio::deadline_timer(
			app->ios_,
			boost::posix_time::seconds(seconds));

	assert(!app->ios_.stopped());

	//auto app = std::dynamic_pointer_cast<neb::core::app::Base>(getParent());

	app->ios_.stopped();

	// cannot do this: shared_from_this shouldnt be used in ctor??

	//timer_.async_wait(boost::bind(&neb::Timer::actor::base::doSomething, shared_from_this()));
}
THIS::~Base()
{
	LOG(lg, neb::core::sl, debug) << __PRETTY_FUNCTION__;
}



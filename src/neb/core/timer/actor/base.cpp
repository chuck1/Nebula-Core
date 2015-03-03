#include <gal/log/log.hpp>

#include <neb/fnd/core/actor/Base.hpp>
#include <neb/fnd/util/debug.hpp>
#include <neb/fnd/app/Base.hpp>

#include <neb/fnd/timer/actor/Base.hpp>

typedef neb::fnd::timer::actor::Base THIS;

THIS::Base(
		std::shared_ptr<neb::fnd::core::actor::base> actor,
		double time):
	neb::fnd::timer::Base(time),
	actor_(actor)
{
	printv_func(DEBUG);

	// cannot do this: shared_from_this shouldnt be used in ctor??

	//timer_.async_wait(boost::bind(&neb::Timer::actor::base::doSomething, shared_from_this()));
}
THIS::~Base()
{
	printv_func(DEBUG);
}



#ifndef NEBULA_TIMER_ACTOR_RELEASE_HPP
#define NEBULA_TIMER_ACTOR_RELEASE_HPP

#include <neb/timer/Actor/Base.hpp>

namespace neb {
	namespace Timer {
		namespace actor {
			class Release: public neb::Timer::actor::base {
				public:
					Release(sp::shared_ptr<neb::core::actor::base>, double);
					virtual void		doSomething();
			};
		}
	}
}

#endif




#ifndef NEB_FND_TIMER_ACTOR_RELEASE_HPP
#define NEB_FND_TIMER_ACTOR_RELEASE_HPP

#include <neb/fnd/timer/actor/Base.hpp>

namespace neb { namespace fnd { namespace timer { namespace actor {
	/** @brief
	 */
	class Release:
		virtual public neb::fnd::timer::actor::Base
	{
		public:
			/** @brief
			 */
			Release(std::shared_ptr<neb::fnd::core::actor::base>, double);
			/** @brief
			 */
			virtual void		doSomething();
	};
}}}}

#endif

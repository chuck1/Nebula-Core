#ifndef NEB_FND_TIMER_ACTOR_RELEASE_HPP
#define NEB_FND_TIMER_ACTOR_RELEASE_HPP

#include <neb/core/timer/actor/Base.hpp>

namespace neb { namespace core { namespace timer { namespace actor {
	/** @brief
	 */
	class Release:
		virtual public neb::core::timer::actor::Base
	{
		public:
			/** @brief
			 */
			Release(std::shared_ptr<neb::core::core::actor::base>, double);
			/** @brief
			 */
			virtual void		doSomething();
	};
}}}}

#endif

#ifndef NEBULA_TIMER_ACTOR_RELEASE_HPP
#define NEBULA_TIMER_ACTOR_RELEASE_HPP

#include <neb/core/timer/Actor/Base.hpp>

namespace neb { namespace core { namespace timer { namespace actor {
	/** @brief
	 *
	 */
	class Release:
		public neb::core::timer::actor::base
	{
		public:
			/** @brief
			 *
			 */
			Release(std::shared_ptr<neb::core::core::actor::base>, double);
			/** @brief
			 *
			 */
			virtual void		doSomething();
	};
}}}}

#endif




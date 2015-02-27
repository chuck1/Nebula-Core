#ifndef NEB_FND_TIMER_ACTOR_RELEASE_HPP
#define NEB_FND_TIMER_ACTOR_RELEASE_HPP

#include <gal/stl/verbosity.hpp>

#include <neb/fnd/timer/actor/Base.hpp>

namespace neb { namespace fnd { namespace timer { namespace actor {
	/** @brief
	 */
	class Release:
		public gal::tmp::Verbosity<neb::fnd::timer::actor::Release>,
		virtual public neb::fnd::timer::actor::Base
	{
		public:
			using gal::tmp::Verbosity<neb::fnd::timer::actor::Release>::printv;
			/** @brief
			 */
			Release(std::shared_ptr<neb::fnd::core::actor::base>, double);
			/** @brief
			 */
			virtual void		doSomething();
	};
}}}}

#endif

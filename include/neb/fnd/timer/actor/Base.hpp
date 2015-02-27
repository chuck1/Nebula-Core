#ifndef NEB_FND_TIMER_ACTOR_BASE_HPP
#define NEB_FND_TIMER_ACTOR_BASE_HPP

#include <gal/stl/verbosity.hpp>

#include <neb/fnd/core/actor/util/decl.hpp>
#include <neb/fnd/timer/Base.hpp>

namespace neb { namespace fnd { namespace timer { namespace actor {
	/** @brief
	 */
	class Base:
		public gal::tmp::Verbosity<neb::fnd::timer::actor::Base>,
		virtual public neb::fnd::timer::Base
	{
		public:
			using gal::tmp::Verbosity<neb::fnd::timer::actor::Base>::printv;
			Base(std::shared_ptr<neb::fnd::core::actor::base> actor, double);
			virtual ~Base();
			/** @brief
			 * what to do when timer expires
			 */
			virtual void						doSomething() = 0;
			//void 							activate();
			std::weak_ptr<neb::fnd::core::actor::base>		actor_;
	};
}}}}

#endif

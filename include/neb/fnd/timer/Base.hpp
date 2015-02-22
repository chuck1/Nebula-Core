#ifndef NEB_FND_TIMER_BASE_HPP
#define NEB_FND_TIMER_BASE_HPP

#include <boost/asio.hpp>
//#include <boost/bind.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>

#include <gal/stl/child.hpp>

#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>

namespace neb { namespace fnd { namespace timer {
	/** @brief
	 *
	 */
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public gal::stl::child<neb::fnd::app::Base>
	{
		public:
			virtual void				step(gal::etc::timestep const & ts);
			virtual void				doSomething() = 0;
			void 					activate();
		protected:
			boost::asio::deadline_timer*		timer_;
			double					time_;
	};
}}}

#endif

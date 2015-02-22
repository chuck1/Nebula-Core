#ifndef NEB_FND_TIMER_UTIL_PARENT_HH
#define NEB_FND_TIMER_UTIL_PARENT_HH

#include <gal/stl/map.hpp>

#include <neb/fnd/itf/Pose.hpp>
#include <neb/fnd/util/parent.hpp>
#include <neb/fnd/timer/Base.hpp>

namespace neb { namespace fnd { namespace timer { namespace util {
	/** @brief parent
	*/
	class Parent:
		virtual public neb::fnd::util::parent<neb::fnd::timer::Base, Parent>
	{
		public:
	};
}}}}

#endif


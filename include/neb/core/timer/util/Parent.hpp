#ifndef NEB_FND_TIMER_UTIL_PARENT_HH
#define NEB_FND_TIMER_UTIL_PARENT_HH

#include <gal/stl/map.hpp>

#include <neb/core/itf/Pose.hh>
#include <neb/core/util/parent.hpp>
#include <neb/core/timer/Base.hpp>

namespace neb { namespace core { namespace timer { namespace util {
	/** @brief parent
	*/
	class Parent:
		virtual public neb::core::util::parent<neb::core::timer::Base, Parent>
	{
		public:
	};
}}}}

#endif


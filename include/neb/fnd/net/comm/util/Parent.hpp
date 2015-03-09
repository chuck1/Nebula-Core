#ifndef NEB_FND_NET_COMM_UTIL_PARENT_HH
#define NEB_FND_NET_COMM_UTIL_PARENT_HH

#include <gal/stl/map.hpp>

#include <neb/fnd/itf/Pose.hpp>
#include <neb/fnd/util/parent.hpp>
#include <neb/fnd/net/comm/Base.hpp>

namespace neb { namespace fnd { namespace net { namespace comm { namespace util {
	/** @brief parent
	*/
	class Parent:
		virtual public neb::fnd::util::parent<neb::fnd::net::comm::Base, Parent>
	{
		public:
			neb::fnd::app::Base* const		get_fnd_app();
	};
}}}}}

#endif


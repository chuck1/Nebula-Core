#ifndef NET_FND_CLIENT_UTIL_PARENT_HPP
#define NET_FND_CLIENT_UTIL_PARENT_HPP

#include <gal/itf/shared.hpp>

#include <neb/fnd/util/parent.hpp>
#include <neb/fnd/util/decl.hpp>
//#include <neb/fnd/net/client/Base.hpp>
#include <neb/fnd/net/comm/util/Parent.hpp>

namespace neb { namespace fnd { namespace net { namespace client { namespace util {
	class Parent:
		//virtual public neb::fnd::util::parent<neb::fnd::net::client::Base, Parent>
		virtual public neb::fnd::net::comm::util::Parent
	{
		public:
			neb::fnd::app::Base * const		get_fnd_app();
	};
}}}}}

#endif


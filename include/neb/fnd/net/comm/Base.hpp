#ifndef NEB_FND_NET_COMM_BASE
#define NEB_FND_NET_COMM_BASE

#include <neb/fnd/tmp/Child.hpp>

#include <neb/fnd/net/comm/util/decl.hpp>

namespace neb { namespace fnd { namespace net { namespace comm {
	class Base:
		virtual public neb::fnd::tmp::Child<neb::fnd::net::comm::util::Parent>
	{
	public:
		virtual void		init(parent_t * const & parent) = 0;
	};
}}}}

#endif

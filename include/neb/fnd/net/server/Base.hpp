#ifndef NEB_FND_NET_SERVER_BASE_HPP
#define NEB_FND_NET_SERVER_BASE_HPP

#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/plug/net/util/decl.hpp>
#include <neb/fnd/plug/ObjectParent.hpp>

namespace neb { namespace fnd { namespace net { namespace server {
	class Base:
		virtual public neb::fnd::tmp::Child<neb::fnd::net::server::util::Parent>,
		public neb::fnd::plug::Parent<neb::fnd::plug::net::server::Base>
	{
		public:
			typedef neb::fnd::plug::Parent<neb::fnd::plug::net::server::Base> N;
			virtual void		init(parent_t * const & parent);
			virtual void		release();
			int			portno;
	};
}}}}

#endif

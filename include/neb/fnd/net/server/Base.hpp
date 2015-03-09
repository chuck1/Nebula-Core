#ifndef NEB_FND_NET_SERVER_BASE_HPP
#define NEB_FND_NET_SERVER_BASE_HPP

#include <gal/stl/verbosity.hpp>

#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/net/comm/util/Parent.hpp>

#include <neb/fnd/plug/net/util/decl.hpp>
#include <neb/fnd/plug/ObjectParent.hpp>

namespace neb { namespace fnd { namespace net { namespace server {
	class Base:
		public gal::tmp::Verbosity<neb::fnd::net::server::Base>,
		virtual public neb::fnd::tmp::Child<neb::fnd::net::server::util::Parent>,
		//virtual public neb::fnd::plug::Parent<neb::fnd::plug::net::server::Base>,
		virtual public neb::fnd::net::comm::util::Parent
	{
		public:
			using CHILD::get_fnd_app;
			using gal::tmp::Verbosity<neb::fnd::net::server::Base>::printv;
			//typedef neb::fnd::plug::Parent<neb::fnd::plug::net::server::Base> N;
			virtual void		init(parent_t * const & parent);
			virtual void		release();
			int			portno;
	};
}}}}

#endif

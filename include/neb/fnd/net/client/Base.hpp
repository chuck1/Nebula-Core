#ifndef NEB_FND_NET_CLIENT_BASE_HPP
#define NEB_FND_NET_CLIENT_BASE_HPP

#include <gal/stl/verbosity.hpp>

#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/tmp/Child.hpp>

#include <neb/fnd/net/comm/Base.hpp>

//#include <neb/fnd/plug/net/util/decl.hpp>
//#include <neb/fnd/plug/ObjectParent.hpp>


namespace neb { namespace fnd { namespace net { namespace client {
	class Base:
		public gal::tmp::Verbosity<neb::fnd::net::client::Base>,
		virtual public neb::fnd::tmp::Child<neb::fnd::net::client::util::Parent>,
		//virtual public neb::fnd::plug::Parent<neb::fnd::plug::net::client::Base>
		virtual public neb::fnd::net::comm::Base
	{
		public:
			using typename neb::fnd::tmp::Child<neb::fnd::net::client::util::Parent>::parent_t;
			using typename neb::fnd::tmp::Child<neb::fnd::net::client::util::Parent>::setParent;
			using typename neb::fnd::tmp::Child<neb::fnd::net::client::util::Parent>::getParent;
			using typename neb::fnd::tmp::Child<neb::fnd::net::client::util::Parent>::get_fnd_app;

			using gal::tmp::Verbosity<neb::fnd::net::client::Base>::printv;
			//typedef neb::fnd::plug::Parent<neb::fnd::plug::net::client::Base> N;
			virtual void		init(parent_t * const & parent);
			virtual void		release();
			std::string		ip;
			int			portno;
	};
}}}}

#endif

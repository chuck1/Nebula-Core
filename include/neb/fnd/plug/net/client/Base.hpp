#ifndef NEB_FND_PLUG_NET_CLIENT_BASE_HPP
#define NEB_FND_PLUG_NET_CLIENT_BASE_HPP

#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/plug/Object.hpp>

namespace neb { namespace fnd { namespace plug { namespace net { namespace client {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::plug::Object<
				neb::fnd::plug::net::client::Base,
				neb::fnd::net::client::Base>
	{
		public:
			virtual void		init(parent_t * const & p) = 0;
	};
}}}}}


#endif

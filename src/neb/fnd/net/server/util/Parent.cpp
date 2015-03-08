#include <neb/fnd/app/Base.hpp>

#include <neb/fnd/net/server/util/Parent.hpp>

typedef neb::fnd::net::server::util::Parent THIS;

neb::fnd::app::Base * const		THIS::get_fnd_app()
{
	auto a = std::dynamic_pointer_cast<neb::fnd::app::Base>(shared_from_this());

	return a.get();
}


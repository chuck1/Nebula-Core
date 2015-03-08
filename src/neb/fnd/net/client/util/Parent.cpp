#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/net/client/util/Parent.hpp>

typedef neb::fnd::net::client::util::Parent THIS;

neb::fnd::app::Base * const		THIS::get_fnd_app()
{
	typedef neb::fnd::app::Base T;
	auto a = std::dynamic_pointer_cast<T>(shared_from_this());
	assert(a);
	return a.get();
}


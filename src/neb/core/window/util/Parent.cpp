#include <neb/fnd/window/util/Parent.hpp>
#include <neb/fnd/app/Base.hpp>

typedef neb::fnd::window::util::Parent THIS;

neb::fnd::app::Base * const		THIS::get_fnd_app()
{
	auto a = dynamic_cast<neb::fnd::app::Base*>(this);
	assert(a);
	return a;
}


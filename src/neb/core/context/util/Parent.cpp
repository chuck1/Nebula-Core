#include <neb/core/context/util/Parent.hpp>
#include <neb/core/window/Base.hpp>
#include <neb/core/window/util/Parent.hpp>

typedef neb::fnd::context::util::Parent THIS;

neb::fnd::app::Base * const		THIS::get_fnd_app()
{
	auto w = is_fnd_window_base();
	assert(w);
	return w->get_fnd_app();
}


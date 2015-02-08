#include <neb/core/window/util/Cast.hpp>
#include <neb/core/window/Base.hpp>

typedef neb::fnd::window::util::Cast THIS;

std::shared_ptr<neb::fnd::window::Base>		THIS::is_fnd_window_base()
{
	auto w = std::dynamic_pointer_cast<neb::fnd::window::Base>(shared_from_this());
	return w;
}


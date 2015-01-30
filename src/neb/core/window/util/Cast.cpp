#include <neb/core/window/util/Cast.hpp>
#include <neb/core/window/Base.hpp>

typedef neb::core::window::util::Cast THIS;

std::shared_ptr<neb::core::window::Base>		THIS::is_fnd_window_base()
{
	auto w = std::dynamic_pointer_cast<neb::core::window::Base>(shared_from_this());
	return w;
}


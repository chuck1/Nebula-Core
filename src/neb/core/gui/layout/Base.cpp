#include <neb/core/gui/layout/Base.hpp>

typedef neb::fnd::gui::layout::Base THIS;

void			THIS::connect(std::shared_ptr<neb::fnd::input::source> const & src)
{
	LOG(lg, neb::gfx::sl, debug) << __PRETTY_FUNCTION__;

	connectKeyFun(src, 10);
	connectCharFun(src, 10);
	connectMouseButtonFun(src, 10);
}



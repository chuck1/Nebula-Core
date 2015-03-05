#include <neb/fnd/gui/layout/Base.hpp>
#include <neb/fnd/gui/layout/util/Cast.hpp>

typedef neb::fnd::gui::layout::util::Cast THIS;

std::shared_ptr<neb::fnd::gui::layout::Base>		THIS::is_gui_layout_base()
{
	auto o = std::dynamic_pointer_cast<neb::fnd::gui::layout::Base>(shared_from_this());
	return o;
}



#include <neb/fnd/gui/object/Terminal.hpp>
#include <neb/fnd/gui/object/util/Cast.hpp>

typedef neb::fnd::gui::object::util::Cast THIS;

std::shared_ptr<neb::fnd::gui::object::Base>		THIS::is_gui_object_base()
{
	auto o = std::dynamic_pointer_cast<neb::fnd::gui::object::Base>(shared_from_this());
	return o;
}
std::shared_ptr<neb::fnd::gui::object::Terminal>	THIS::is_gui_object_terminal()
{
	auto o = std::dynamic_pointer_cast<neb::fnd::gui::object::Terminal>(shared_from_this());
	return o;
}


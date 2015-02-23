#include <neb/fnd/gui/object/util/Parent.hpp>
#include <neb/fnd/gui/layout/Base.hpp>
#include <neb/fnd/gui/layout/util/Parent.hpp>

typedef neb::fnd::gui::object::util::Parent THIS;

neb::fnd::app::Base* const	THIS::get_fnd_app()
{
	auto l = is_gui_layout_base();
	assert(l);
	return l->get_fnd_app();
}



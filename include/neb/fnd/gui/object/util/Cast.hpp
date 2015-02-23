#ifndef NEB_GFX_GUI_OBJECT_UTIL_CAST_HPP
#define NEB_GFX_GUI_OBJECT_UTIL_CAST_HPP

#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/gui/object/util/decl.hpp>

namespace neb { namespace fnd { namespace gui { namespace object { namespace util {
	class Cast:
		virtual public neb::fnd::itf::shared
	{
		std::shared_ptr<neb::fnd::gui::object::Base>		is_gui_object_base();
		std::shared_ptr<neb::fnd::gui::object::Terminal>	is_gui_object_terminal();
	};
}}}}}

#endif

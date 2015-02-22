#ifndef NEB_FND_GUI_LAYOUT_UTIL_CAST_HPP
#define NEB_FND_GUI_LAYOUT_UTIL_CAST_HPP

#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/util/decl.hpp>

namespace neb { namespace fnd { namespace gui { namespace layout { namespace util {
	class Cast:
		virtual public neb::fnd::itf::shared
	{
		public:
		std::shared_ptr<neb::fnd::gui::layout::Base>		is_gfx_gui_layout_base();
	};
}}}}}

#endif

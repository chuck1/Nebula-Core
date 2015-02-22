#ifndef NEB_FND_GUI_LAYOUT_UTIL_PARENT_HH
#define NEB_FND_GUI_LAYOUT_UTIL_PARENT_HH

#include <neb/core/util/parent.hpp>
#include <neb/core/gui/layout/base.hpp>

namespace neb { namespace fnd { namespace gui { namespace layout { namespace util {
	class Parent:
		public neb::fnd::util::parent<neb::fnd::gui::layout::base, parent>
	{
		public:
			neb::fnd::app::Base*		get_fnd_app();
	};
}}}}}

#endif

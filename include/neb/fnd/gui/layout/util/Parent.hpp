#ifndef NEB_FND_GUI_LAYOUT_UTIL_PARENT_HH
#define NEB_FND_GUI_LAYOUT_UTIL_PARENT_HH

#include <neb/fnd/util/parent.hpp>
#include <neb/fnd/gui/layout/Base.hpp>

namespace neb { namespace fnd { namespace gui { namespace layout { namespace util {
	class Parent:
		public neb::fnd::util::parent<neb::fnd::gui::layout::Base, Parent>
	{
		public:
			neb::fnd::app::Base*		get_fnd_app();
	};
}}}}}

#endif

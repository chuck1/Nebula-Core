#ifndef NEB_FND_GUI_OBJECT_UTIL_PARENT_HPP
#define NEB_FND_GUI_OBJECT_UTIL_PARENT_HPP

#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/util/parent.hpp>

#include <neb/fnd/gui/object/__Base.hpp>
#include <neb/fnd/gui/object/util/Cast.hpp>
#include <neb/fnd/gui/layout/util/Cast.hpp>
#include <neb/fnd/gui/object/util/decl.hpp>

namespace neb { namespace fnd { namespace gui { namespace object { namespace util {
	/** @brief parent
	*/
	class Parent:
		virtual public neb::fnd::util::parent<neb::fnd::gui::object::Base, Parent>,
		virtual public neb::fnd::gui::layout::util::Cast,
		virtual public neb::fnd::gui::object::util::Cast
	{
		public:
			neb::fnd::app::Base* const	get_fnd_app();
	};
}}}}}

#endif


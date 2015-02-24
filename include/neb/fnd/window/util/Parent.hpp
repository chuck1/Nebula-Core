#ifndef NEBULA_CORE_WINDOW_UTIL_PARENT_HH
#define NEBULA_CORE_WINDOW_UTIL_PARENT_HH

#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/util/parent.hpp>
#include <neb/fnd/window/Base.hpp>

namespace neb { namespace fnd { namespace window { namespace util {

	class Parent:
		virtual public neb::fnd::util::parent<neb::fnd::window::Base, Parent>
	{
		public:
			void					render();
			neb::fnd::app::Base * const		get_fnd_app();
	};
}}}}

#endif


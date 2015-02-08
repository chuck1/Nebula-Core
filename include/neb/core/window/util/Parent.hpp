#ifndef NEBULA_CORE_WINDOW_UTIL_PARENT_HH
#define NEBULA_CORE_WINDOW_UTIL_PARENT_HH

#include <neb/core/util/parent.hpp>
#include <neb/core/window/Base.hpp>

namespace neb { namespace fnd { namespace window { namespace util {

	class Parent:
		virtual public neb::fnd::util::parent<neb::fnd::window::Base, Parent>
	{
		public:
			virtual void		render() = 0;
	};
}}}}

#endif


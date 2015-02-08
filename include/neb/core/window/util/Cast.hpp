#ifndef NEBULA_FND_WINDOW_UTIL_CAST_HH
#define NEBULA_FND_WINDOW_UTIL_CAST_HH

#include <neb/core/itf/shared.hpp>
#include <neb/core/window/util/decl.hpp>

namespace neb { namespace fnd { namespace window { namespace util {
	class Cast:
		virtual public neb::fnd::itf::shared
	{
		public:
			std::shared_ptr<neb::fnd::window::Base>		is_fnd_window_base();
	};

}}}}

#endif


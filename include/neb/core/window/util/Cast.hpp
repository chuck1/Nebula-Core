#ifndef NEBULA_FND_WINDOW_UTIL_CAST_HH
#define NEBULA_FND_WINDOW_UTIL_CAST_HH

#include <neb/core/itf/shared.hpp>
#include <neb/core/window/util/decl.hpp>

namespace neb { namespace core { namespace window { namespace util {
	class Cast:
		virtual public neb::core::itf::shared
	{
		public:
			std::shared_ptr<neb::core::window::Base>		is_fnd_window_base();
	};

}}}}

#endif


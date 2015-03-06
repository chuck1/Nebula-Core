#ifndef NEB_FND_APP_UTIL_FLAG_HPP
#define NEB_FND_APP_UTIL_FLAG_HPP

#include <gal/etc/flag.hpp>

namespace neb { namespace fnd { namespace app {
	namespace util {
		DEFINE_FLAG(flag,
				((SHOULD_RELEASE)(1 << 0))
				((INIT___BASE)(1 << 1))
				((INIT_GLEW)(1 << 2))
				((INIT_GLFW)(1 << 3))
				((FIRST_CONTEXT)(1 << 4))
				((PLUGIN_GRAPHICS)(1 << 5))
				((PLUGIN_PHYSICS)(1 << 6))
				((PLUGIN_NETWORK)(1 << 7))
			   )
	}
}}}

#endif

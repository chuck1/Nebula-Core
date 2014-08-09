#ifndef NEB_CORE_CORE_SCENE_UTIL_CAST_HPP
#define NEB_CORE_CORE_SCENE_UTIL_CAST_HPP

#include <neb/core/util/shared.hpp>

namespace neb {
	namespace core {
		namespace core {
			namespace scene {
				namespace util {
					class cast:
						virtual public neb::std::shared
					{
						shared_ptr<neb::core::scene::base>		isSceneBase();
					};
				}
			}
		}
	}
}

#endif

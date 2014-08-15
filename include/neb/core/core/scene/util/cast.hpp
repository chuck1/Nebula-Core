#ifndef NEB_CORE_CORE_SCENE_UTIL_CAST_HPP
#define NEB_CORE_CORE_SCENE_UTIL_CAST_HPP

#include <neb/core/util/shared.hpp>
#include <neb/core/core/scene/util/decl.hpp>

using namespace std;

namespace neb { namespace core { namespace core { namespace scene { namespace util {
	/** @brief %cast
	 */
	class cast:
		virtual public neb::std::shared
	{
		public:
			shared_ptr<neb::core::core::scene::base>		isSceneBase();
	};
}}}}}

#endif

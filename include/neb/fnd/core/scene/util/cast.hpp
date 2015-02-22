#ifndef NEB_CORE_CORE_SCENE_UTIL_CAST_HPP
#define NEB_CORE_CORE_SCENE_UTIL_CAST_HPP

#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/core/scene/util/decl.hpp>

using namespace std;

namespace neb { namespace fnd { namespace core { namespace scene { namespace util {
	/** @brief %cast
	 */
	class cast:
		virtual public neb::fnd::itf::shared
	{
		public:
			shared_ptr<neb::fnd::core::scene::base>		isSceneBase();
	};
}}}}}

#endif

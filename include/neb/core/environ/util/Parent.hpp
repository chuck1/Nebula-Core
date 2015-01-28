#ifndef NEB_CORE_ENVIRON_UTIL_PARENT_HH
#define NEB_CORE_ENVIRON_UTIL_PARENT_HH

#include <neb/core/environ/util/decl.hpp>
//#include <neb/core/util/parent.hpp>

namespace neb { namespace core { namespace environ { namespace util {
	class Parent
		//virtual public neb::core::util::parent<neb::core::context::Base, Parent>
	{
		public:
			virtual std::weak_ptr<neb::core::environ::two>			createEnvironTwo() = 0;
			virtual std::weak_ptr<neb::core::environ::SceneDefault>		createEnvironSceneDefault() = 0;
			virtual std::weak_ptr<neb::core::environ::NormalMap>		createEnvironNormalMap() = 0;
			virtual std::weak_ptr<neb::core::environ::shadow::point>	createEnvironShadowPoint() = 0;
			virtual std::weak_ptr<neb::core::environ::shadow::directional>	createEnvironShadowDirectional() = 0;
			virtual std::weak_ptr<neb::core::environ::vis_depth>		createEnvironVisDepth() = 0;
	};
}}}}

#endif






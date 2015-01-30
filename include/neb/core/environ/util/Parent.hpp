#ifndef NEB_CORE_ENVIRON_UTIL_PARENT_HPP
#define NEB_CORE_ENVIRON_UTIL_PARENT_HPP

#include <memory>

#include <neb/core/context/util/Cast.hpp>
#include <neb/core/environ/util/decl.hpp>
#include <neb/core/util/parent.hpp>

namespace neb { namespace core { namespace environ { namespace util {
	class Parent:
		virtual public neb::core::util::parent<neb::core::environ::Base, Parent>,
		virtual public neb::core::context::util::Cast
	{
		public:
			virtual std::weak_ptr<neb::core::environ::Two>				createEnvironTwo() = 0;
			virtual std::weak_ptr<neb::core::environ::SceneDefault>			createEnvironSceneDefault() = 0;
			virtual std::weak_ptr<neb::core::environ::shadow::Point>		createEnvironShadowPoint() = 0;
			virtual std::weak_ptr<neb::core::environ::shadow::Directional>		createEnvironShadowDirectional() = 0;
			virtual std::weak_ptr<neb::core::environ::visualization::Depth>		createEnvironVisualizationDepth() = 0;
			virtual std::weak_ptr<neb::core::environ::visualization::Normal>	createEnvironVisualizationNormal() = 0;
	};
}}}}

#endif

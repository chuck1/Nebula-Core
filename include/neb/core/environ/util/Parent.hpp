#ifndef NEB_CORE_ENVIRON_UTIL_PARENT_HPP
#define NEB_CORE_ENVIRON_UTIL_PARENT_HPP

#include <memory>

#include <neb/core/context/util/Cast.hpp>
#include <neb/core/environ/util/decl.hpp>
#include <neb/core/util/decl.hpp>
#include <neb/core/util/parent.hpp>

namespace neb { namespace fnd { namespace environ { namespace util {
	class Parent:
		virtual public neb::fnd::util::parent<neb::fnd::environ::Base, Parent>,
		virtual public neb::fnd::context::util::Cast
	{
		public:
			neb::fnd::app::Base* const						get_fnd_app();
			virtual std::weak_ptr<neb::fnd::environ::Two>				createEnvironTwo() = 0;
			virtual std::weak_ptr<neb::fnd::environ::SceneDefault>			createEnvironSceneDefault() = 0;
			virtual std::weak_ptr<neb::fnd::environ::shadow::Point>		createEnvironShadowPoint() = 0;
			virtual std::weak_ptr<neb::fnd::environ::shadow::Directional>		createEnvironShadowDirectional() = 0;
			virtual std::weak_ptr<neb::fnd::environ::visualization::Depth>		createEnvironVisualizationDepth() = 0;
			virtual std::weak_ptr<neb::fnd::environ::visualization::Normal>	createEnvironVisualizationNormal() = 0;
	};
}}}}

#endif

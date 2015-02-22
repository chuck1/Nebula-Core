#ifndef NEB_CORE_ENVIRON_UTIL_PARENT_HPP
#define NEB_CORE_ENVIRON_UTIL_PARENT_HPP

#include <memory>

#include <neb/fnd/context/util/Cast.hpp>
#include <neb/fnd/environ/util/decl.hpp>
#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/util/parent.hpp>

namespace neb { namespace fnd { namespace environ { namespace util {
	class Parent:
		virtual public neb::fnd::util::parent<neb::fnd::environ::Base, Parent>,
		virtual public neb::fnd::context::util::Cast
	{
		public:
			neb::fnd::app::Base* const						get_fnd_app();
			virtual std::weak_ptr<neb::fnd::environ::Two>				createEnvironTwo();
			virtual std::weak_ptr<neb::fnd::environ::SceneDefault>			createEnvironSceneDefault();
			virtual std::weak_ptr<neb::fnd::environ::shadow::Point>			createEnvironShadowPoint();
			virtual std::weak_ptr<neb::fnd::environ::shadow::Directional>		createEnvironShadowDirectional();
			virtual std::weak_ptr<neb::fnd::environ::visualization::Depth>		createEnvironVisualizationDepth();
			virtual std::weak_ptr<neb::fnd::environ::visualization::Normal>		createEnvironVisualizationNormal();
	};
}}}}

#endif

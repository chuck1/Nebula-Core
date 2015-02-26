#ifndef NEB_CORE_ENVIRON_SHADOW_POINT_HPP
#define NEB_CORE_ENVIRON_SHADOW_POINT_HPP

#include <neb/fnd/environ/shadow/Base.hpp>
#include <neb/fnd/environ/Single.hpp>
#include <neb/fnd/environ/SceneDefault.hpp>
#include <neb/fnd/camera/util/decl.hpp>
#include <neb/fnd/camera/view/shadow/Point.hpp>
#include <neb/fnd/camera/view/shadow/Directional.hpp>
#include <neb/fnd/core/light/Point.hpp>
#include <neb/fnd/core/light/Directional.hpp>

namespace neb { namespace fnd { namespace environ { namespace shadow {
	class Point:
		virtual public neb::fnd::environ::shadow::Base<neb::fnd::core::light::Point>,
		virtual public neb::fnd::environ::multiple<neb::fnd::camera::view::shadow::Point>
	{
		public:
			virtual void		init(parent_t * const & p);
			virtual void		release();
	};
}}}}

#endif

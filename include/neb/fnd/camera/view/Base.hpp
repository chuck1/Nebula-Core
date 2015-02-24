#ifndef NEB_FND_CAMERA_VIEW_BASE_HPP
#define NEB_FND_CAMERA_VIEW_BASE_HPP

#include <memory>
#include <map>

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/itf/shared.hpp>
//#include <neb/fnd/core/actor/util/decl.hpp>
#include <neb/fnd/camera/view/util/Cast.hpp>
#include <neb/fnd/environ/util/decl.hpp>
#include <neb/fnd/glsl/program/util/decl.hpp>
#include <neb/fnd/plug/ObjectParent.hpp>
#include <neb/fnd/plug/gfx/camera/util/decl.hpp>

//#include <neb/gfx/window/Base.hpp>
//#include <neb/gfx/camera/view/Base.hpp>

namespace neb { namespace fnd { namespace camera { namespace view {
	class Base:
		virtual public neb::fnd::camera::view::util::Cast,
		virtual public neb::fnd::tmp::Child<neb::fnd::environ::Base>,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::gfx::camera::view::Base>
	{
		public:
			typedef neb::fnd::plug::Parent<neb::fnd::plug::gfx::camera::view::Base> G;
			virtual void		init(parent_t * const & p);
			virtual void		load(neb::fnd::glsl::program::Base * const & p);
	};
}}}}

#endif

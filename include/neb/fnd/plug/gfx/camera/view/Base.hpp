#ifndef NEB_FND_PLUG_GFX_CAMERA_VIEW_BASE_HPP
#define NEB_FND_PLUG_GFX_CAMERA_VIEW_BASE_HPP

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/camera/util/decl.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace camera { namespace view {
	class Base:
		virtual public neb::fnd::tmp::Child<neb::fnd::camera::view::Base>
	{
		public:
			typedef neb::fnd::camera::view::Base FND;
	};
}}}}}}

#endif

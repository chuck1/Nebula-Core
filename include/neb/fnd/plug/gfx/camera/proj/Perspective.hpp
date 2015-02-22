#ifndef NEB_FND_PLUG_GFX_CAMERA_PROJ_PERSPECTIVE_HPP
#define NEB_FND_PLUG_GFX_CAMERA_PROJ_PERSPECTIVE_HPP

#include <neb/fnd/plug/gfx/camera/proj/Base.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace camera { namespace proj {
	class Perspective:
		virtual public neb::fnd::plug::gfx::camera::proj::Base
	{
		public:
			typedef neb::fnd::camera::proj::Perspective FND;
	};
}}}}}}


#endif

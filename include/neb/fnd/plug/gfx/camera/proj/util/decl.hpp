#ifndef NEB_FND_PLUG_GFX_CAMERA_PROJ_UTIL_DECL_HPP
#define NEB_FND_PLUG_GFX_CAMERA_PROJ_UTIL_DECL_HPP

namespace neb { namespace fnd { namespace plug { namespace gfx {
	namespace camera
	{
		namespace proj
		{
			struct type
			{
				enum
				{
					ORTHO,
					PERSPECTIVE
				};
			};
			class Base;
			class Perspective;
			class Ortho;
		}
	}
}}}}

#endif

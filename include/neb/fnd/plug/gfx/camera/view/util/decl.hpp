#ifndef NEB_FND_PLUG_GFX_CAMERA_VIEW_UTIL_DECL_HPP
#define NEB_FND_PLUG_GFX_CAMERA_VIEW_UTIL_DECL_HPP

namespace neb { namespace fnd { namespace plug { namespace gfx {
	namespace camera
	{
		namespace view
		{
			struct type
			{
				enum
				{
					RIDEALONG,
					SHADOW_POINT
				};
			};
			namespace shadow
			{
				class Base;
				class Point;
				class Directional;
				class Spot;
			}
			class Base;
			class Ridealong;
		}
	}
}}}}

#endif

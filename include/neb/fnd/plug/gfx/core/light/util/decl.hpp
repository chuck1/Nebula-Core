#ifndef NEB_FND_PLUG_GFX_CORE_LIGHT_UTIL_DECL_HPP
#define NEB_FND_PLUG_GFX_CORE_LIGHT_UTIL_DECL_HPP

namespace neb { namespace fnd { namespace plug {
	namespace gfx
	{
		namespace core
		{
			namespace light
			{
				struct type
				{
					enum
					{
						POINT,
						SPOT,
						DIRECTIONAL
					};
				};
				class Base;
				class Point;
				class Spot;
				class Directional;
			}
		}
	}
}}}

#endif


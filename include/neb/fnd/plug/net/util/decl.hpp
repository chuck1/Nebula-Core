#ifndef NEB_FND_PLUG_NET_UTIL_DECL_HPP
#define NEB_FND_PLUG_NET_UTIL_DECL_HPP

namespace neb { namespace fnd { namespace plug {
	namespace net
	{
		struct type
		{
			enum
			{
				NONE = 0,
				LOCAL = 1,
				REMOTE = 2
			};
		};
		namespace app
		{
			class Base;
		}
		namespace core
		{
			namespace scene
			{
				class Base;
			}
			namespace actor
			{
				class Base;
			}
			namespace light
			{
				class Base;
				class Point;
				class Spot;
				class Directional;
			}
		}
		namespace server
		{
			class Base;
		}
		namespace client
		{
			class Base;
		}
		class communicating;
	}
}}}

#endif


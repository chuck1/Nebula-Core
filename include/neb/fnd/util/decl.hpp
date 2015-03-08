#ifndef NEBULA_TYPES_HH
#define NEBULA_TYPES_HH

#include <memory>

/** @brief root namespace for @gru */
namespace neb
{
	namespace fnd
	{	
		struct net_type
		{
			enum
			{
				NONE = 0,
				LOCAL = 1,
				REMOTE = 2
			};
		};

		/** @brief %app */
		namespace app
		{
			class Base;
		}
		namespace gui
		{
			namespace layout
			{
				class Base;
			}
		}

		namespace window
		{
			class Base;
		}
		namespace drawable
		{
			class Base;
		}
		namespace net
		{
			namespace server
			{
				namespace util
				{
					class Parent;
				}
				class Base;
			}
			namespace client
			{
				namespace util
				{
					class Parent;
				}
				class Base;
			}
			class communicating;
		}

		class RenderDesc;
		class DebugBuffer;
	}
}

#endif

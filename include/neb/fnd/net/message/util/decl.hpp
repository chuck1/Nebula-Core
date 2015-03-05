#ifndef NEBULA_MESSAGE_TYPES
#define NEBULA_MESSAGE_TYPES

namespace neb { namespace fnd { namespace net {
	/** @brief %Message */
	namespace msg
	{
		class Base;
		/** @brief %Actor */
		namespace actor
		{
			class Base;
			class Create;
			class Update;
			/** @brief %Control */
			namespace control
			{
				/** @brief %rigidbody */
				namespace rigidbody
				{
					class Base;
					class Create;
					class Update;
				}
			}
		}
	}
}}}

#endif


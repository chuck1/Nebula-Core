#ifndef NEBULA_CORE_POSE
#define NEBULA_CORE_POSE

#include <neb/core/math/pose.hpp>

namespace neb { namespace core { namespace itf {

	class Pose
	{
		public:
			virtual neb::core::math::pose				getPoseGlobal() const = 0;
			virtual neb::core::math::pose				getPose() const = 0;
	};

}}}

#endif

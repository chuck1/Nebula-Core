#ifndef NEBULA_CORE_POSE
#define NEBULA_CORE_POSE

#include <neb/fnd/math/pose.hpp>

namespace neb { namespace fnd { namespace itf {

	class Pose
	{
		public:
			virtual neb::fnd::math::pose				getPoseGlobal() const = 0;
			virtual neb::fnd::math::pose				getPose() const = 0;
	};

}}}

#endif

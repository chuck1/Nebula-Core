#ifndef NEBULA_CORE_POSE
#define NEBULA_CORE_POSE

#include <gal/math/pose.hpp>

namespace neb { namespace fnd { namespace itf {

	class Pose
	{
		public:
			virtual gal::math::pose				getPoseGlobal() const = 0;
			virtual gal::math::pose				getPose() const = 0;
	};

}}}

#endif

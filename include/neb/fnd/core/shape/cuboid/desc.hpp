#ifndef NEB_CORE_CORE_SHAPE_CUBOID_DESC_HPP
#define NEB_CORE_CORE_SHAPE_CUBOID_DESC_HPP

#include <neb/fnd/math/pose.hpp>

namespace neb { namespace fnd { namespace core { namespace shape { namespace cuboid {

	struct Desc {

		Desc(neb::fnd::math::pose pose, glm::vec3 scale):
			pose_(pose),
			scale_(scale),
			density_(1.0)
		{}
		Desc(glm::vec3 scale):
			scale_(scale),
			density_(1.0)
		{}
		Desc():
			scale_(1.0),
			density_(1.0)
		{}

		neb::fnd::math::pose		pose_;
		glm::vec3			scale_;
		float				density_;
	};

}}}}}

#endif


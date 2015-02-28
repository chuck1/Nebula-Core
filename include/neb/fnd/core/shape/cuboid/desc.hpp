#ifndef NEB_CORE_CORE_SHAPE_CUBOID_DESC_HPP
#define NEB_CORE_CORE_SHAPE_CUBOID_DESC_HPP

#include <gal/math/pose.hpp>

namespace neb { namespace fnd { namespace core { namespace shape { namespace cuboid {

	struct Desc {

		Desc(gal::math::pose pose, glm::vec3 scale):
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

		gal::math::pose		pose_;
		glm::vec3			scale_;
		float				density_;
	};

}}}}}

#endif


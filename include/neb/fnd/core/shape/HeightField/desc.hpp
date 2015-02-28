#ifndef NEB_CORE_CORE_SHAPE_HEIGHT_FIELD_DESC_HPP
#define NEB_CORE_CORE_SHAPE_HEIGHT_FIELD_DESC_HPP

#include <vector>

#include <gal/math/pose.hpp>
#include <neb/fnd/math/color/color.hpp>

namespace neb { namespace fnd { namespace core { namespace shape { namespace HeightField {

	struct desc {
		desc():
			i1(1),
			i2(1),
			i3(1),
			r(17),
			c(17),
			w(10.0),
			h(10.0),
			hs(1.0)
		{}
		desc(gal::math::pose pose, glm::vec3 scale):
			pose_(pose),
			scale_(scale),
			i1(1),
			i2(1),
			i3(1),
			r(17),
			c(17),
			w(10.0),
			h(10.0),
			hs(1.0)
		{}
		desc(glm::vec3 scale):
			scale_(scale),
			i1(1),
			i2(1),
			i3(1),
			r(17),
			c(17),
			w(10.0),
			h(10.0),
			hs(1.0)
		{}

		gal::math::pose	pose_;
		glm::vec3		scale_;


		unsigned int	i1;
		unsigned int	i2;
		unsigned int	i3;
		std::vector<float>	fc;

		unsigned int	r;
		unsigned int	c;
		float		w;
		float		h;
		float		hs;
	};

}}}}}

#endif




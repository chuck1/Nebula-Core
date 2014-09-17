#ifndef NEB_CORE_CORE_SHAPE_HEIGHT_FIELD_DESC_HPP
#define NEB_CORE_CORE_SHAPE_HEIGHT_FIELD_DESC_HPP

namespace neb { namespace core { namespace core { namespace shape { namespace HeightField {

	struct desc {
		desc() {}
		desc(neb::core::pose pose, glm::vec3 scale):
			pose_(pose),
			scale_(scale)
		{}
		desc(glm::vec3 scale):
			scale_(scale)
		{}

		neb::core::pose		pose_;
		glm::vec3		scale_;


		unsigned int	i1;
		unsigned int	i2;
		unsigned int	i3;
		float		f1;
		float		f2;
		float		f3;
	};

}}}}}

#endif




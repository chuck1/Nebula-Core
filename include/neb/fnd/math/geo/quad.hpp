#ifndef __MATH_GEO_QUAD_H__
#define __MATH_GEO_QUAD_H__

#include <neb/fnd/math/geo/polygon.hpp>

namespace neb { namespace fnd {
namespace math {
	namespace geo {
		struct quad: polygon {
			//quad();
		};
		struct rectangle: quad {
			rectangle(glm::vec3 c, glm::vec3 x, glm::vec3 n, float w, float h);
		};
	}
}
}}

#endif



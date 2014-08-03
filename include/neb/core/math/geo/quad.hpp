#ifndef __MATH_GEO_QUAD_H__
#define __MATH_GEO_QUAD_H__

//#include <PxPhysicsAPI.h>

#include <neb/typedef.hpp>
#include <neb/math/geo/polygon.hpp>

namespace math {
	namespace geo {
		struct quad: polygon {
			//quad();
		};
		struct rectangle: quad {
			rectangle(vec3 c, vec3 x, vec3 n, float w, float h);
		};
	}
}

#endif



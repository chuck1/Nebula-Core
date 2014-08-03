#ifndef __MATH_GEO_POLYGON_H__
#define __MATH_GEO_POLYGON_H__

#include <memory>
#include <vector>

#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include <neb/typedef.hpp>

namespace math {
	namespace geo {
		class vertex {
			public:
				vertex() {};
				vertex(vec3 np, vec3 nn, vec2 ntc): p(np,1.0), n(nn), tc(ntc) {}
				void		serialize(boost::archive::polymorphic_iarchive & ar, unsigned int const & version);
				void		serialize(boost::archive::polymorphic_oarchive & ar, unsigned int const & version);
				void		print(int sl);
				/** @brief position */
				vec4		p;
				/** @brief normal */
				vec3		n;
				/** @brief texture coordinate */
				vec2		tc;
		};
		struct tri {
			tri(std::shared_ptr<vertex>, std::shared_ptr<vertex>, std::shared_ptr<vertex>);

			std::shared_ptr<vertex>		v_[3];

			void	reset_normals();
		};
		struct polygon {
			int	triangle_count();


			std::vector< sp::shared_ptr<tri> >		triangles_;

		};
	}
}

#endif



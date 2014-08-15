#ifndef __MATH_GEO_POLYGON_H__
#define __MATH_GEO_POLYGON_H__

#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

using namespace std;

namespace math {
	namespace geo {
		class vertex {
			public:
				vertex() {};
				vertex(glm::vec3 np, glm::vec3 nn, glm::vec2 ntc): p(np,1.0), n(nn), tc(ntc) {}
				void		serialize(boost::archive::polymorphic_iarchive & ar, unsigned int const & version);
				void		serialize(boost::archive::polymorphic_oarchive & ar, unsigned int const & version);
				void		print(int sl);
				/** @brief position */
				glm::vec4		p;
				/** @brief normal */
				glm::vec3		n;
				/** @brief texture coordinate */
				glm::vec2		tc;
		};
		struct tri {
			tri(shared_ptr<vertex>, shared_ptr<vertex>, shared_ptr<vertex>);

			shared_ptr<vertex>		v_[3];

			void	reset_normals();
		};
		struct polygon {
			int	triangle_count();


			vector< shared_ptr<tri> >		triangles_;

		};
	}
}

#endif



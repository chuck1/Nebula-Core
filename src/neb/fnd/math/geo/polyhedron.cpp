#include <cstdlib>
#include <cassert>

#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/math/geo/polygon.hpp>
#include <neb/fnd/math/geo/polyhedron.hpp>

typedef neb::fnd::math::geo::polyhedron THIS;

THIS::polyhedron(): polygons_(NULL), nbPolys_(0)
{
}
unsigned int			THIS::getNbTriangles()
{
	std::cout << __PRETTY_FUNCTION__ << this << std::endl;
	assert(polygons_);
	
	unsigned int n = 0;

	for(unsigned int i = 0; i < nbPolys_; i++)
	{
		n += polygons_[i].getNbTriangles();
	}

	return n;
}
neb::fnd::math::geo::triangle*	THIS::getTriangles()
{
	
	std::cout << __PRETTY_FUNCTION__ << this << std::endl;
	assert(polygons_);
	
	unsigned int nbTriangles = getNbTriangles();
	
	assert(nbTriangles);

	triangle* triangles = new triangle[nbTriangles];
	

	unsigned int c = 0;
	for(unsigned int i = 0; i < nbPolys_; i++)
	{
		triangle* t = polygons_[i].getTriangles();
		assert(t);

		for(unsigned int j = 0; j < polygons_[i].getNbTriangles(); j++)
		{
			triangles[c++] = t[j];
		}
	}
	
	return triangles;
}


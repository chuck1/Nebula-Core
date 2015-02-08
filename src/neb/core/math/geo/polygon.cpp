#include <neb/core/util/decl.hpp>
#include <neb/core/math/geo/polygon.hpp>

typedef neb::fnd::math::geo::polygon THIS;

THIS::polygon(): triangles_(NULL), nbTriangles_(0)
{
}
neb::fnd::math::geo::triangle*	THIS::getTriangles()
{
	//std::cout << __PRETTY_FUNCTION__ << this << std::endl;
	return triangles_;
}
unsigned int		THIS::getNbTriangles()
{
	//std::cout << __PRETTY_FUNCTION__ << this << std::endl;
	return nbTriangles_;
}
void			THIS::setTriangles(
		neb::fnd::math::geo::triangle* triangles,
		unsigned int nbTriangles)
{
	triangles_ = triangles;
	nbTriangles_ = nbTriangles;
}


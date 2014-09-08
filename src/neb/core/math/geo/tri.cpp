#include <neb/core/math/geo/polygon.hpp>

math::geo::triangle::triangle()
{
	verts_[0] = NULL;
	verts_[1] = NULL;
	verts_[2] = NULL;
}
math::geo::triangle::triangle(vertex* v0, vertex* v1, vertex* v2)
{
	verts_[0] = v0;
	verts_[1] = v1;
	verts_[2] = v2;
}
math::geo::triangle&	math::geo::triangle::operator=(math::geo::triangle const & t)
{
	verts_[0] = t.verts_[0];
	verts_[1] = t.verts_[1];
	verts_[2] = t.verts_[2];
	return *this;
}







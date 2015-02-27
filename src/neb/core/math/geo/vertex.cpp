#include <iomanip>

#include <gal/log/log.hpp>

#include <neb/fnd/util/debug.hpp>
#include <neb/fnd/math/geo/vertex.hpp>
#include <neb/fnd/math/serialization/glm.hpp>

typedef neb::fnd::math::geo::vertex THIS;

void			THIS::serialize(
		boost::archive::polymorphic_iarchive & ar,
		unsigned int const & version)
{
	ar & p;
	ar & n;
	ar & tc;
}
void			THIS::serialize(
		boost::archive::polymorphic_oarchive & ar,
		unsigned int const & version)
{
	ar & p;
	ar & n;
	ar & tc;
}
void			THIS::print(int sl)
{
	printf("p   %8f%8f%8f   n%8f%8f%8f tcp%8f%8f\n",
		p[0],
		p[1],
		p[2],
		n[0],
		n[1],
		n[2],
		tc[0],
		tc[1]);
}



#include <iomanip>

#include <gal/log/log.hpp>

#include <neb/fnd/util/debug.hpp>
#include <neb/fnd/math/geo/vertex.hpp>
#include <neb/fnd/math/serialization/glm.hpp>
#include <neb/fnd/util/log.hpp>

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
	LOG(lg, neb::fnd::sl, (severity_level)sl)
		<< std::setw(4) << " "
		<< std::setw(4) << "p"
		<< std::setw(8) << p[0]
		<< std::setw(8) << p[1]
		<< std::setw(8) << p[2]
		<< std::setw(4) << "n"
		<< std::setw(8) << n[0]
		<< std::setw(8) << n[1]
		<< std::setw(8) << n[2]
		<< std::setw(4) << "tcp"
		<< std::setw(8) << tc[0]
		<< std::setw(8) << tc[1];
}



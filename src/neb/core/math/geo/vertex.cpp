#include <iomanip>

#include <gal/log/log.hpp>

#include <neb/core/debug.hh>
#include <neb/core/math/geo/polygon.hpp>
#include <neb/core/math/Serialization/glm.hpp>
#include <neb/core/util/log.hpp>


void				math::geo::vertex::serialize(boost::archive::polymorphic_iarchive & ar, unsigned int const & version) {
	ar & p;
	ar & n;
	ar & tc;
}
void				math::geo::vertex::serialize(boost::archive::polymorphic_oarchive & ar, unsigned int const & version) {
	ar & p;
	ar & n;
	ar & tc;
}

void		math::geo::vertex::print(int sl) {
	if(DEBUG_NEB) LOG(lg, neb::core::sl, (severity_level)sl)
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



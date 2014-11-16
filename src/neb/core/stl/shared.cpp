
#include <neb/core/itf/shared.hpp>

neb::core::itf::shared::shared()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void				neb::core::itf::shared::release()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
/*void					neb::itf::shared::step(gal::etc::timestep const & ts) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}*/


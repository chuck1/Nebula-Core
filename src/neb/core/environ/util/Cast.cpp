#include <neb/fnd/environ/util/Cast.hpp>
#include <neb/fnd/environ/Two.hpp>
#include <neb/fnd/environ/Three.hpp>

typedef neb::fnd::environ::util::Cast THIS;

std::shared_ptr<THIS::TWO>		THIS::is_fnd_environ_two()
{
	return std::dynamic_pointer_cast<TWO>(shared_from_this());
}
std::shared_ptr<THIS::THREE>		THIS::is_fnd_environ_three()
{
	return std::dynamic_pointer_cast<THREE>(shared_from_this());
}



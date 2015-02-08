
#include <neb/core/core/actor/rigidbody/desc.hpp>

void							neb::fnd::core::actor::desc::release()
{
}
std::shared_ptr<neb::fnd::core::actor::base>		neb::fnd::core::actor::desc::visit(
		neb::fnd::core::scene::base * const scene
		) const
{

	return std::shared_ptr<neb::fnd::core::actor::base>();

}

std::shared_ptr<neb::fnd::core::actor::base>		neb::fnd::core::actor::rigidbody::desc::visit(
		neb::fnd::core::scene::base * const scene
		) const
{

	return std::shared_ptr<neb::fnd::core::actor::base>();

}



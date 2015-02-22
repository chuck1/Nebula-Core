
#include <neb/fnd/core/scene/base.hpp>
#include <neb/fnd/core/actor/rigiddynamic/desc.hpp>

typedef neb::fnd::core::actor::rigiddynamic::Desc THIS;

THIS::Desc()
{
}
THIS::Desc(neb::fnd::math::pose npose):
	neb::fnd::core::actor::rigidbody::desc(npose)
{
}

std::shared_ptr<neb::fnd::core::actor::base>		THIS::Desc::visit(
		neb::fnd::core::scene::base * const scene
		) const
{
	assert(scene);
	return scene->createActorRigidDynamic(this).lock();
}



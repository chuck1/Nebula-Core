
#include <neb/core/core/scene/base.hpp>
#include <neb/core/core/actor/rigiddynamic/desc.hpp>

typedef neb::core::core::actor::rigiddynamic::Desc THIS;

THIS::Desc()
{
}
THIS::Desc(neb::core::math::pose npose):
	neb::core::core::actor::rigidbody::desc(npose)
{
}

std::shared_ptr<neb::core::core::actor::base>		THIS::Desc::visit(
		neb::core::core::scene::base * const scene
		) const
{
	assert(scene);
	return scene->createActorRigidDynamic(this).lock();
}



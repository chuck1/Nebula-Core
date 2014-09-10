
#include <neb/core/core/scene/base.hpp>
#include <neb/core/core/actor/rigiddynamic/desc.hpp>



neb::core::core::actor::rigiddynamic::desc::desc()
{
}
neb::core::core::actor::rigiddynamic::desc::desc(neb::core::pose npose):
	neb::core::core::actor::rigidbody::desc(npose)
{
}
void				neb::core::core::actor::rigiddynamic::desc::load(
		boost::archive::xml_iarchive & ar,
		unsigned int const & version)
{
	neb::core::core::actor::desc::__load(ar, version);
	neb::core::core::actor::rigidbody::desc::__load(ar, version);

	__load(ar, version);
}
void				neb::core::core::actor::rigiddynamic::desc::save(
		boost::archive::xml_oarchive & ar,
		unsigned int const & version) const
{
	neb::core::core::actor::desc::__save(ar, version);
	neb::core::core::actor::rigidbody::desc::__save(ar, version);

	__save(ar, version);
};

std::shared_ptr<neb::core::core::actor::base>		neb::core::core::actor::rigiddynamic::desc::visit(
		neb::core::core::scene::base * const scene
		) const
{
	assert(scene);
	return scene->createActorRigidDynamic(this).lock();
}


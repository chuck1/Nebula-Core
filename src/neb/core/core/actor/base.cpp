
#include <gal/log/log.hpp>

#include <neb/fnd/util/log.hpp>
#include <neb/fnd/util/config.hpp>
#include <neb/fnd/util/debug.hpp>
#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/core/actor/base.hpp>
#include <neb/fnd/core/actor/util/decl.hpp>
#include <neb/fnd/core/scene/base.hpp>
#include <neb/fnd/game/weapon/SimpleProjectile.hpp>

typedef neb::fnd::core::actor::base THIS;

neb::fnd::core::actor::base::base():
	density_(2.0),
	health_(1.0)
{



	LOG(lg, neb::fnd::core::actor::sl, debug) << __FUNCSIG__;
}
/*neb::fnd::core::actor::base::base(std::shared_ptr<neb::fnd::core::actor::util::parent> parent):
  gal::stl::child<parent_t>(parent.get()),
  density_(10.0)
  {
  LOG(lg, neb::fnd::core::actor::sl, debug) << __FUNCSIG__;
  assert(parent);
  }*/
neb::fnd::core::actor::base::~base() {
	LOG(lg, neb::fnd::core::actor::sl, debug) << __FUNCSIG__;

	assert(neb::fnd::core::actor::util::parent::map_.empty());
	assert(neb::fnd::core::shape::util::parent::map_.empty());

}
void		neb::fnd::core::actor::base::init(parent_t * const & p)
{
	LOG(lg, neb::fnd::core::actor::sl, debug) << __FUNCSIG__;

	neb::fnd::core::actor::util::parent::initChildren(this);
	neb::fnd::core::shape::util::parent::initChildren(this);
}
void		neb::fnd::core::actor::base::release() {
	LOG(lg, neb::fnd::core::actor::sl, debug) << __FUNCSIG__;

	gal::itf::__release::release();

	neb::fnd::core::actor::util::parent::clear();
	neb::fnd::core::shape::util::parent::clear();

}
/*std::shared_ptr<neb::fnd::core::actor::util::parent>	neb::fnd::core::actor::base::get_parent() {
  auto parent(parent_.lock());
  assert(parent);
  return parent;
  }*/
bool							neb::fnd::core::actor::base::hasScene() const
{
	LOG(lg, neb::fnd::core::actor::sl, debug) << __FUNCSIG__;

	if(!hasParent()) return false;

	auto scene = dynamic_cast<neb::fnd::core::scene::base*>(getParent());

	if(scene) return true;

	auto actor = dynamic_cast<neb::fnd::core::actor::base*>(getParent());

	assert(actor);

	return actor->hasScene();
}
neb::fnd::core::scene::base*				neb::fnd::core::actor::base::getScene() const
{
	LOG(lg, neb::fnd::core::actor::sl, debug) << __FUNCSIG__;

	assert(hasParent());

	auto scene = dynamic_cast<neb::fnd::core::scene::base*>(getParent());

	if(scene) return scene;

	auto actor = dynamic_cast<neb::fnd::core::actor::base*>(getParent());

	assert(actor);

	assert(actor != this);

	return actor->getScene();
}
neb::fnd::math::pose				neb::fnd::core::actor::base::getPose() const
{
	return pose_;
}
neb::fnd::math::pose				neb::fnd::core::actor::base::getPoseGlobal() const
{
	LOG(lg, neb::fnd::core::actor::sl, debug) << __FUNCSIG__;

	auto p = getParent()->getPoseGlobal() * getPose();

	return p;
}
void			neb::fnd::core::actor::base::v_set_pose_data(
		neb::fnd::math::pose const & pose)
{
	__set_pose_data(pose);
}
void			neb::fnd::core::actor::base::__set_pose_data(
		neb::fnd::math::pose const & pose)
{
	pose_ = pose;

	neb::fnd::core::shape::util::parent::callbackPose(pose);

	flag_.set(neb::fnd::core::actor::util::flag::E::SHOULD_UPDATE);
}
void		neb::fnd::core::actor::base::step(gal::etc::timestep const & ts)
{
	LOG(lg, neb::fnd::core::actor::sl, debug) << __FUNCSIG__;

	//typedef neb::fnd::core::actor::util::parent A;

	actors::step(ts);
	shapes::step(ts);

	//A::map_.for_each([&] (A::map_type::iterator it) {
	//		it->ptr_->step(ts);
	//		});

	//S::map_.for_each([&] (S::map_type::iterator it) {
	//		it->ptr_->step(ts);
	//		});

}
std::weak_ptr<neb::fnd::core::shape::base>		neb::fnd::core::actor::base::createShapeCube(
		neb::fnd::math::pose const & pose,
		double size)
{
	neb::fnd::core::shape::cuboid::Desc desc(
			pose,
			glm::vec3(size)
			);

	auto shape = createShapeCuboid(desc);

	return shape;

}

std::weak_ptr<neb::fnd::core::shape::base>		neb::fnd::core::actor::base::createShapeLightSpot(
		neb::fnd::math::pose const & pose,
		glm::vec3 direction)
{
	auto shape = createShapeBase(pose).lock();

	shape->createLightSpot(direction);

	return shape;

}
void			THIS::load(ba::polymorphic_iarchive & ar, unsigned int const & v)
{
	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(gal::itf::shared);
	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::fnd::core::actor::base);

	__serialize(ar, v);
}
void			THIS::save(ba::polymorphic_oarchive & ar, unsigned int const & v) const
{
	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(gal::itf::shared);
	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::fnd::core::actor::base);

	const_cast<THIS*>(this)->__serialize(ar, v);
}
typedef neb::fnd::game::weapon::SimpleProjectile Weapon;
std::weak_ptr<Weapon>			THIS::createWeaponSimpleProjectile(
		std::shared_ptr<neb::fnd::input::source> src,
		double size,
		double damage,
		double velocity)
{
	//auto self(isPxActorBase());
	
	std::shared_ptr<Weapon> weap(new Weapon());

	//weap->actor_ = self;
	weap->setParent(this);

	weap->connect(src);

	weap->velocity_ = velocity;
	weap->size_ = size;
	weap->damage_ = damage;

	neb::fnd::game::weapon::util::parent::insert(weap);

	return weap;
}











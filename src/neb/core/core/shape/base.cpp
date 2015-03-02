#include <glm/gtx/transform.hpp>

#include <gal/stl/map.hpp>

#include <gal/log/log.hpp>

#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/math/geo/polygon.hpp>
#include <neb/fnd/util/config.hpp>
#include <neb/fnd/util/debug.hpp>
#include <neb/fnd/core/actor/Base.hpp>
#include <neb/fnd/core/shape/base.hpp>

#include <neb/fnd/core/light/Point.hpp>

#include <neb/fnd/plug/gfx/core/shape/Base.hpp>

typedef neb::fnd::core::shape::base THIS;

THIS::base():
	scale_(1.0)
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
}
THIS::~base()
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
}
bool							THIS::hasScene()
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);

	if(!hasParent()) return false;

	auto shape = dynamic_cast<THIS*>(getParent());
	
	if(shape) return shape->hasScene();

	auto actor = dynamic_cast<neb::fnd::core::actor::base*>(getParent());

	assert(actor);
	
	return actor->hasScene();
}

neb::fnd::core::scene::base*				THIS::getScene()
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
	
	auto shape = dynamic_cast<THIS*>(getParent());
	
	if(shape) return shape->getScene();

	auto actor = dynamic_cast<neb::fnd::core::actor::base*>(getParent());

	assert(actor);
	
	return actor->getScene();
}
gal::math::pose				THIS::getPoseGlobal() const
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
	
	return getParent()->getPoseGlobal() * pose_;
}
gal::math::pose				THIS::getPose() const
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
	
	return pose_;
}
void			THIS::__set_pose_data(
		gal::math::pose const & gpose)
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);

	auto pose = gpose * pose_;
	neb::fnd::core::shape::util::parent::callbackPose(pose);
	neb::fnd::core::light::util::parent::callbackPose(pose);

	if(G::has_object())
		G::get_object()->v_set_pose_data(this, pose);
}
void					THIS::init(neb::fnd::core::shape::util::parent * const & p)
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
	
	setParent(p);
	
	auto app = get_fnd_app();

	if(!G::has_object()) {
		G::make_object<THIS, int>(
				app->_M_graphics_plugin,
				neb::fnd::plug::gfx::core::shape::type::BASE);
	}

	//auto me = std::dynamic_pointer_cast<THIS>(shared_from_this());

	//auto scene = get_parent()->get_scene();

	// type

	// program
	/*	if(image_.length() == 0) {
		program_ = neb::program_name::LIGHT;
		} else {
	 ** @todo replace this with something better... *
	//flag_.set(neb::fnd::core::shape::flag::e::IMAGE);

	program_ = neb::program_name::IMAGE;
	}
	*/

	neb::fnd::core::shape::util::parent::initChildren(this);
	neb::fnd::core::light::util::parent::initChildren(this);
}
void					THIS::release()
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);

	neb::fnd::core::shape::util::parent::map_.clear();
	neb::fnd::core::light::util::parent::map_.clear();
}
void						THIS::step(
		gal::etc::timestep const & ts)
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
	neb::fnd::core::shape::util::parent::step(ts);
	neb::fnd::core::light::util::parent::step(ts);
}
void			THIS::load(
		ba::polymorphic_iarchive & ar,
		unsigned int const & v)
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
	__serialize(ar, v);
}
void			THIS::save(
		ba::polymorphic_oarchive & ar,
		unsigned int const & v) const
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
	const_cast<THIS*>(this)->__serialize(ar, v);
}
std::weak_ptr<neb::fnd::core::light::base>		THIS::createLightPoint()
{
	printv_func(DEBUG);
	//auto app = get_fnd_app();

	typedef neb::fnd::core::light::Point L;
	//typedef neb::fnd::plug::gfx::core::light::Point G;
	
	L* l = new L();
	auto light = std::shared_ptr<L>(l);
	
	
	neb::fnd::core::light::util::parent::insert(light);
	
	light->init(this);

	return light;
}







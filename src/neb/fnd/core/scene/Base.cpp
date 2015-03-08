#include <stdio.h>

#include <gal/stl/deleter.hpp>

#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/util/debug.hpp>
#include <neb/fnd/util/config.hpp>
#include <neb/fnd/core/actor/Base.hpp>
#include <neb/fnd/core/actor/rigidbody/desc.hpp>
#include <neb/fnd/core/actor/util/decl.hpp>
#include <neb/fnd/core/light/base.hpp>
#include <neb/fnd/core/light/util/light_count.hpp>
#include <neb/fnd/core/shape/base.hpp>
#include <neb/fnd/core/scene/util/decl.hpp>
#include <neb/fnd/core/scene/util/parent.hpp>
#include <neb/fnd/game/game/base.hpp>
#include <neb/fnd/game/game/util/decl.hpp>

#include <neb/fnd/plug/gfx/core/scene/Base.hpp>
#include <neb/fnd/plug/phx/core/scene/Base.hpp>
#include <neb/fnd/plug/net/core/scene/Base.hpp>

#include <neb/fnd/core/actor/Base.hpp>
#include <neb/fnd/core/actor/rigidstatic/base.hpp>
#include <neb/fnd/core/actor/rigiddynamic/Base.hpp>

typedef neb::fnd::core::scene::base THIS;

typedef std::weak_ptr<neb::fnd::core::actor::base>	wbase;

#include <neb/fnd/core/scene/Base.hpp>

THIS::base():
	last_(0)
{
	printv_func(DEBUG);
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
}
THIS::~base()
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
}
neb::fnd::game::game::base*	THIS::get_game()
{
	auto p = getParent();
	
	auto m = dynamic_cast<neb::fnd::game::map::Base*>(p);
	assert(m);

	auto mp = m->getParent();

	auto g = dynamic_cast<neb::fnd::game::game::base*>(mp);
	assert(g);

	return g;
}
void				THIS::init(parent_t * const & p)
{
	printv_func(DEBUG);

	setParent(p);

	neb::fnd::core::actor::util::parent::init(this);

	neb::fnd::core::actor::util::parent::initChildren(this);


	auto game = get_game();
	
	auto app = get_fnd_app();

	if(app->G::has_object())
	if(!G::has_object())
		G::make_object<THIS, int>(
				app->get_graphics_plugin(),
				0);

	if(app->P::has_object())
	if(!P::has_object())
		P::make_object<THIS, int>(
				app->get_physics_plugin(),
				0);

	if(app->N::has_object())
	if(!N::has_object()) {
		int nt = game->get_net_type();

		printv(DEBUG, "net type = %i\n", nt);

		if(nt != neb::fnd::plug::net::type::NONE)
			N::make_object<THIS, int>(
					app->get_network_plugin(),
					nt);
	}
	
}
void			THIS::__release()
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
	
	neb::fnd::core::actor::util::parent::clear();
}
gal::math::pose		THIS::getPose() const
{
	return gal::math::pose();
}		
gal::math::pose		THIS::getPoseGlobal() const
{
	return gal::math::pose();
}
void				THIS::add_deferred(
		std::shared_ptr<neb::fnd::core::actor::base> actor)
{
	/** @todo deprecated */
	abort();
	//actors_deferred_[actor->name_] = actor;
}
void		THIS::step(gal::etc::timestep const & ts)
{
	actors::step(ts);

	if(P::has_object())
		P::get_object()->step(ts);
}
std::weak_ptr<neb::fnd::core::actor::base>		THIS::createActorRigidStaticCube(
		gal::math::pose pose,
		double size)
{
	auto actor = createActorRigidStaticUninitialized().lock();
	actor->pose_ = pose;

	printv(
			DEBUG,
			"fnd::scene p = %16f %16f %16f\n",
			actor->pose_.pos_.x,
			actor->pose_.pos_.y,
			actor->pose_.pos_.z);

	actor->init(this);

	// create shape

	auto shape = actor->createShapeCube(
			gal::math::pose(), size);

	// reinitialize in order to apply filtering to shape
	/// @todo consider implementing refresh-type function instead
	actor->init(this);

	return actor;
}
std::weak_ptr<neb::fnd::core::actor::base>		THIS::createActorRigidStaticCuboid(
		gal::math::pose pose,
		glm::vec3 size)
{
	auto actor = createActorRigidStaticUninitialized().lock();

	actor->pose_ = pose;

	printv(
			DEBUG,
			"fnd::scene p = %16f %16f %16f\n",
			actor->pose_.pos_.x,
			actor->pose_.pos_.y,
			actor->pose_.pos_.z);

	actor->init(this);
	
	// create shape
	
	auto shape = actor->createShapeCuboid(
			neb::fnd::core::shape::cuboid::Desc(
				size));

	// reinitialize in order to apply filtering to shape
	/// @todo consider implementing refresh-type function instead
	actor->init(this);

	return actor;
}
typedef neb::fnd::core::actor::base ACTOR_BASE;
weak_ptr<ACTOR_BASE>	THIS::createActorRigidDynamicCuboid(
		neb::fnd::core::actor::rigidbody::desc const &		actor_desc,
		neb::fnd::core::shape::cuboid::Desc const &		shape_desc)
{

	auto actor = createActorRigidDynamicUninitialized().lock();

	actor->pose_ = actor_desc.pose;

	actor->init(this);

	// shape
	auto shape = actor->createShapeCuboid(shape_desc);

	/// @todo consider implementing refresh-type function instead
	actor->init(this);

	return actor;
}
weak_ptr<neb::fnd::core::actor::base>		THIS::createActorLightPoint(glm::vec3 p) {

	// actor
	auto actor = createActorBase(gal::math::pose(p)).lock();

	// shape	
	auto shape = actor->createShapeBase(gal::math::pose()).lock();

	// light
	auto light = shape->createLightPoint();

	return actor;	
}
std::weak_ptr<neb::fnd::core::actor::base>		THIS::createActorLightDirectional(glm::vec3 p)
{
	auto actor = createActorBase(gal::math::pose()).lock();

	auto shape = actor->createShapeBase(gal::math::pose()).lock();

	auto light = shape->createLightDirectional(p);

	return actor;	
}
std::weak_ptr<neb::fnd::core::actor::base>		THIS::createActor(
		neb::fnd::core::actor::desc const * const & desc
		)
{
	assert(desc);
	return desc->visit(this);
}
void			THIS::addActor(
		std::shared_ptr<neb::fnd::core::actor::base> const & actor
		)
{
	insert(actor);
	actor->init(this);
}
void			THIS::load(
		boost::archive::polymorphic_iarchive & ar,
		unsigned int const & version)
{
	printv_func(DEBUG);

	ar & boost::serialization::make_nvp("flag",flag_);
	ar & boost::serialization::base_object<neb::fnd::core::actor::util::parent>(*this);
}
void			THIS::save(
		boost::archive::polymorphic_oarchive & ar,
		unsigned int const & version) const
{
	ar & boost::serialization::make_nvp("flag",flag_);
	ar & boost::serialization::base_object<neb::fnd::core::actor::util::parent>(*this);
}


void			THIS::draw(neb::fnd::RenderDesc const & rd)
{
	printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
	//if(G::has_object())
	G::get_object()->draw(rd);
}
void			THIS::release()
{
	printv_func(DEBUG);

	neb::fnd::core::scene::base::__release();
}
wbase			THIS::createActorBase(gal::math::pose pose)
{
	printv_func(DEBUG);

	auto self(dynamic_pointer_cast<THIS>(shared_from_this()));

	typedef neb::fnd::core::actor::base T;

	std::shared_ptr<T> actor(new T(), gal::stl::deleter<T>());

	actor->pose_ = pose;

	insert(actor);

	actor->init(this);

	return actor;
}
wbase		THIS::createActorRigidStaticUninitialized()
{
	printv_func(DEBUG);

	auto self(dynamic_pointer_cast<THIS>(shared_from_this()));

	typedef neb::fnd::core::actor::rigidstatic::base T;

	std::shared_ptr<T> actor(new T(), gal::stl::deleter<T>());

	neb::fnd::core::actor::util::parent::insert_no_init(actor);
	
	// filtering
	actor->simulation_.word0 = phx::filter::filter::type::STATIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::STATIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	return actor;
}
wbase		THIS::createActorRigidDynamicUninitialized()
{
	printv_func(DEBUG);

	auto self(dynamic_pointer_cast<THIS>(shared_from_this()));

	typedef neb::fnd::core::actor::rigiddynamic::base T;

	std::shared_ptr<T> actor(new T(), gal::stl::deleter<T>());

	neb::fnd::core::actor::util::parent::insert(actor);

	actor->simulation_.word0 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	return actor;
}
wbase			THIS::createActorRigidDynamic()
{
	printv_func(DEBUG);

	auto self(dynamic_pointer_cast<THIS>(shared_from_this()));

	typedef neb::fnd::core::actor::rigiddynamic::base T;

	std::shared_ptr<T> actor(new T(), gal::stl::deleter<T>());

	neb::fnd::core::actor::util::parent::insert(actor);

	actor->simulation_.word0 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	actor->init(this);

	return actor;
}
wbase			THIS::createActorRigidDynamic(
		neb::fnd::core::actor::rigiddynamic::Desc const * const & desc)
{
	printv_func(DEBUG);

	auto self(dynamic_pointer_cast<THIS>(shared_from_this()));

	typedef neb::fnd::core::actor::rigiddynamic::base T;

	std::shared_ptr<T> actor(new T(), gal::stl::deleter<T>());

	neb::fnd::core::actor::util::parent::insert(actor);

	actor->simulation_.word0 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	actor->init(this);

	return actor;
}
void			THIS::drawPhysxVisualization(
		neb::fnd::RenderDesc const & desc)
{
	printv_func(DEBUG);
	//auto app = get_fin_app();

	if(!flag_.all(neb::fnd::core::scene::util::flag::PHYSX_VISUALIZATION)) return;

	// visual debugging
	if(P::has_object()) { //if(px_scene_) {
		// get the data

		neb::fnd::DebugBuffer db = P::get_object()->get_debug_buffer();
		
		if(G::has_object())
			G::get_object()->draw_debug_buffer(desc, db);

		//auto e = neb::could_be<neb::gfx::environ::base, neb::gfx::environ::three>(context->environ_);
		//if(e)
	}
}






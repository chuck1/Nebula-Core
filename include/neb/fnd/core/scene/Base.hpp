#ifndef __GLUTPP_SCENE_H__
#define __GLUTPP_SCENE_H__

#include <vector>

#include <gal/etc/flag.hpp>
#include <gal/stl/verbosity.hpp>

#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/util/decl.hpp>

#include <neb/fnd/core/scene/util/flag.hpp>
#include <neb/fnd/core/scene/util/decl.hpp>

#include <neb/fnd/core/actor/util/parent.hpp>
#include <neb/fnd/core/actor/util/decl.hpp>

#include <neb/fnd/core/shape/util/decl.hpp>

#include <neb/fnd/drawable/Base.hpp>
#include <neb/fnd/net/util/decl.hpp>
#include <neb/fnd/RenderDesc.hpp>
#include <neb/fnd/game/game/util/decl.hpp>

#include <neb/fnd/plug/gfx/util/decl.hpp>
#include <neb/fnd/plug/phx/util/decl.hpp>
#include <neb/fnd/plug/net/util/decl.hpp>

#include <neb/fnd/plug/ObjectParent.hpp>

typedef weak_ptr<neb::fnd::core::actor::base> wbase;

namespace neb { namespace fnd { namespace core { namespace scene {
	/** 
	 * @ingroup group_core
	 * @brief Base
	 */
	class base:
		virtual public neb::fnd::tmp::Child<neb::fnd::core::scene::util::parent>,
		virtual public neb::fnd::core::actor::util::parent,
		virtual public neb::fnd::drawable::Base,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::gfx::core::scene::Base>,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::phx::core::scene::Base>,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::net::core::scene::Base>,
		virtual public gal::tmp::Verbosity<neb::fnd::core::scene::base>
	{
		public:
			using CHILD::get_fnd_app;
			using gal::tmp::Verbosity<neb::fnd::core::scene::base>::printv;
			typedef neb::fnd::plug::Parent<neb::fnd::plug::gfx::core::scene::Base> G;
			typedef neb::fnd::plug::Parent<neb::fnd::plug::phx::core::scene::Base> P;
			typedef neb::fnd::plug::Parent<neb::fnd::plug::net::core::scene::Base> N;
			typedef neb::fnd::core::scene::util::parent	parent_t;
			typedef neb::fnd::util::parent<neb::fnd::core::actor::__base, neb::fnd::core::actor::util::parent>		actors;
		public:
			base();
			virtual ~base();
			virtual void			init(parent_t * const & p);
			virtual void			release();
			virtual void			step(gal::etc::timestep const & ts);
		protected:
			void				__release();
			void				__step(gal::etc::timestep const & ts);
		public:
			/***/
			virtual void			load(
					boost::archive::polymorphic_iarchive & ar,
					unsigned int const & version);
			virtual void			save(
					boost::archive::polymorphic_oarchive & ar,
					unsigned int const & version) const;
			BOOST_SERIALIZATION_SPLIT_MEMBER();
			/***/
			virtual void			draw(
					neb::fnd::RenderDesc const & rd);
			void				drawPhysxVisualization(
					neb::fnd::RenderDesc const & desc);


			/***/
			wbase				createActor(neb::fnd::core::actor::desc const * const &);
			virtual wbase			createActorBase(gal::math::pose);
			virtual wbase			createActorRigidStaticUninitialized();
			/***/
			virtual wbase			createActorRigidDynamic();
			virtual wbase			createActorRigidDynamic(neb::fnd::core::actor::rigiddynamic::Desc const * const &);
			/***/
			virtual wbase			createActorRigidDynamicUninitialized();
			virtual wbase			createActorLightPoint(glm::vec3 p);
			virtual wbase			createActorLightDirectional(glm::vec3 p);
			wbase				createActorRigidStaticCuboid(gal::math::pose, glm::vec3);
			wbase				createActorRigidStaticCube(gal::math::pose pose, double size);
			wbase				createActorRigidDynamicCuboid(
					neb::fnd::core::actor::rigidbody::desc const &,
					neb::fnd::core::shape::cuboid::Desc const &);
		public:
			gal::math::pose			getPose() const;
			gal::math::pose			getPoseGlobal() const;
			neb::fnd::game::game::base*	get_game();
			/** @brief
			 *
			 */
			void					add_deferred(
					shared_ptr<neb::fnd::core::actor::base>);
			/** @brief
			 *
			 */
			void					addActor(std::shared_ptr<neb::fnd::core::actor::base> const &);
			/** @brief
			 *
			 */
			/** @} */
	public:
			neb::fnd::core::scene::util::flag					flag_;
			std::map< string, std::shared_ptr<neb::fnd::core::actor::base> >	actors_deferred_;
			float									last_;
};
}}}}

#endif

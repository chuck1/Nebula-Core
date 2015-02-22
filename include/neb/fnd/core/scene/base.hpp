#ifndef __GLUTPP_SCENE_H__
#define __GLUTPP_SCENE_H__

#include <vector>

#include <gal/etc/flag.hpp>
//#include <gal/stl/map.hpp>

#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/core/scene/util/flag.hpp>
#include <neb/fnd/core/scene/util/decl.hpp>
#include <neb/fnd/core/actor/util/decl.hpp>
#include <neb/fnd/core/shape/util/decl.hpp>
#include <neb/fnd/core/actor/util/parent.hpp>
#include <neb/fnd/drawable/Base.hpp>
#include <neb/fnd/net/util/decl.hpp>
#include <neb/fnd/plug/gfx/util/decl.hpp>

//#include <neb/fnd/core/actor/rigidbody/desc.hpp>
//#include <neb/fnd/core/shape/cuboid/desc.hpp>

typedef weak_ptr<neb::fnd::core::actor::base> wbase;

namespace neb { namespace fnd { namespace core { namespace scene {
		/** 
		 * @ingroup group_core
		 * @brief Base
		 */
		class base:
			virtual public neb::fnd::tmp::Child<neb::fnd::core::scene::util::parent>,
			virtual public neb::fnd::core::actor::util::parent,
			virtual public neb::fnd::drawable::Base
		{
			public:
				using CHILD::get_fnd_app;
				typedef neb::fnd::core::scene::util::parent									parent_t;
				typedef neb::fnd::util::parent<neb::fnd::core::actor::__base, neb::fnd::core::actor::util::parent>		actors;
				base();
				virtual ~base();
				virtual void				init(parent_t * const & p) = 0;
				void					__init(parent_t * const & p);
				void					__release();
				/** @name Main Loop @{ */
				virtual void				step(gal::etc::timestep const & ts);
				/** @} */
				virtual void				load(boost::archive::polymorphic_iarchive & ar, unsigned int const & version);
				virtual void				save(boost::archive::polymorphic_oarchive & ar, unsigned int const & version) const;
				BOOST_SERIALIZATION_SPLIT_MEMBER();
			public:
				neb::fnd::math::pose			getPose() const;
				neb::fnd::math::pose			getPoseGlobal() const;
				/** @brief
				 *
				 */
				void					add_deferred(
						shared_ptr<neb::fnd::core::actor::base>);
				/** @name convenience functions
				 * @{
				 */
				virtual wbase				createActorBase(
						neb::fnd::math::pose pose) = 0;
				/** @brief create empty actor with point light
				*/
				wbase					createActor(
						neb::fnd::core::actor::desc const * const &);
				/** @brief
				 *
				 */
				void					addActor(
						std::shared_ptr<neb::fnd::core::actor::base> const &);
				/** @brief
				 *
				 */
				virtual wbase				createActorLightPoint(
						glm::vec3 p);
				/** @brief
				 *
				 */
				virtual wbase				createActorLightDirectional(
						glm::vec3 p);

				/** @brief
				 *
				 */
				wbase					createActorRigidStaticCuboid(
						neb::fnd::math::pose,
						glm::vec3);
				/** @brief
				 *
				 */
				wbase					createActorRigidStaticCube(
						neb::fnd::math::pose pose,
						double size);
				/** @brief
				 *
				 */
				virtual wbase				createActorRigidDynamic() = 0;
				/** @brief
				 *
				 */
				virtual wbase				createActorRigidDynamic(
						neb::fnd::core::actor::rigiddynamic::Desc const * const &) = 0;
				/** @brief
				 *
				 */
				wbase					createActorRigidDynamicCuboid(
						neb::fnd::core::actor::rigidbody::desc const &,
						neb::fnd::core::shape::cuboid::Desc const &);
				/** @brief create rigidstatic
				 *
				 * @note typeof returned actor will be
				 * determined by final implementation of this
				 *
				 * @warning return actor is not initialized
				 */
				virtual wbase				createActorRigidStaticUninitialized() = 0;
				virtual wbase				createActorRigidDynamicUninitialized() = 0;
				/** @} */
			public:
				neb::fnd::core::scene::util::flag					flag_;
				std::map< string, std::shared_ptr<neb::fnd::core::actor::base> >	actors_deferred_;
				float									last_;
			protected:
				std::shared_ptr<neb::fnd::net::core::scene::Base>			_M_network_object;
				std::shared_ptr<neb::fnd::plug::gfx::core::scene::Base>			_M_graphics_object;
				//std::shared_ptr<neb::fnd::plug::gfx::core::actor::Base>		_M_graphics_object;
		};
}}}}

#endif

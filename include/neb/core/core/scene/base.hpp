#ifndef __GLUTPP_SCENE_H__
#define __GLUTPP_SCENE_H__

#include <vector>

#include <gal/etc/flag.hpp>
//#include <gal/stl/map.hpp>
#include <gal/stl/child.hpp>

#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>

#include <neb/core/util/decl.hpp>
#include <neb/core/core/scene/util/flag.hpp>
#include <neb/core/core/scene/util/decl.hpp>
#include <neb/core/core/actor/util/decl.hpp>
#include <neb/core/core/shape/util/decl.hpp>
#include <neb/core/core/actor/util/parent.hpp>

//#include <neb/core/core/actor/rigidbody/desc.hpp>
//#include <neb/core/core/shape/cuboid/desc.hpp>

typedef weak_ptr<neb::fnd::core::actor::base> wbase;

namespace neb { namespace fnd { namespace core { namespace scene {
		/** 
		 * @ingroup group_core
		 * @brief Base
		 */
		class base:
			virtual public gal::stl::child<neb::fnd::core::scene::util::parent>,
			virtual public neb::fnd::core::actor::util::parent
		{
			public:
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
		};
}}}}

#endif

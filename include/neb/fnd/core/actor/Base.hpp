#ifndef NEBULA_ACTOR_BASE_HH
#define NEBULA_ACTOR_BASE_HH

#include <memory>

#include <boost/signals2.hpp>

#include <boost/archive/polymorphic_xml_iarchive.hpp>
#include <boost/archive/polymorphic_xml_oarchive.hpp>
#include <boost/serialization/map.hpp>

#include <gal/stl/verbosity.hpp>
#include <gal/math/serialization/glm.hpp>

#include <gal/math/pose.hpp>
#include <neb/fnd/filter.hpp>
#include <neb/fnd/core/actor/__Base.hpp>
#include <neb/fnd/core/actor/util/decl.hpp>
#include <neb/fnd/core/actor/util/flag.hpp>
#include <neb/fnd/core/actor/util/parent.hpp>
#include <neb/fnd/core/actor/util/Cast.hpp>
#include <neb/fnd/core/shape/base.hpp>
#include <neb/fnd/core/shape/util/decl.hpp>
#include <neb/fnd/core/shape/util/parent.hpp>
#include <neb/fnd/core/shape/cuboid/desc.hpp>
#include <neb/fnd/game/weapon/util/parent.hpp>
#include <neb/fnd/game/weapon/util/decl.hpp>

#include <neb/fnd/plug/phx/core/actor/util/decl.hpp>
#include <neb/fnd/plug/phx/core/shape/util/decl.hpp>

namespace neb { namespace fnd { namespace core { namespace actor {
	/** @brief %base */
	class base:
		virtual public neb::fnd::core::actor::__base,
		virtual public neb::fnd::itf::serializable,
		virtual public neb::fnd::core::actor::util::Cast,
		virtual public neb::fnd::core::actor::util::parent,
		virtual public neb::fnd::core::shape::util::parent,
		virtual public neb::fnd::game::weapon::util::parent,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::gfx::core::actor::Base>,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::phx::core::actor::Base>,
		//virtual public neb::fnd::plug::Parent<neb::fnd::plug::phx::core::actor::Base>,
		virtual public gal::tmp::Verbosity<neb::fnd::core::actor::base>
	{
		public:
			using CHILD::get_fnd_app;
			using gal::tmp::Verbosity<neb::fnd::core::actor::base>::printv;
			typedef neb::fnd::plug::Parent<neb::fnd::plug::gfx::core::actor::Base> G;
			typedef neb::fnd::plug::Parent<neb::fnd::plug::phx::core::actor::Base> P;
			//typedef neb::fnd::plug::Parent<neb::fnd::plug::phx::core::actor::Base> P;
			typedef neb::fnd::util::parent<neb::fnd::core::actor::__base, neb::fnd::core::actor::util::parent>	actors;
			typedef neb::fnd::util::parent<neb::fnd::core::shape::base, neb::fnd::core::shape::util::parent>	shapes;
			typedef neb::fnd::core::actor::util::parent A;
			typedef neb::fnd::core::shape::util::parent S;

			//typedef neb::fnd::core::actor::__base> parent_t;
			/** @brief default constructor */
			base();
			/** @brief constructor */
			//base(std::shared_ptr<parent_t> parent);
			virtual ~base();
			virtual void					init(parent_t * const &);
			virtual void					release();
			virtual void					step(gal::etc::timestep const & ts);
			virtual gal::math::pose				getPose() const;
			virtual gal::math::pose				getPoseGlobal() const;
			bool						hasScene() const;
			neb::fnd::core::scene::base*			getScene() const;

			void			hit();
			void			damage(double);
			void			set_pose_global(
					gal::math::pose const & pose);
			//std::shared_ptr<neb::fnd::core::actor::util::parent>		get_parent();
			/** @brief set pose data
			 * set the pose variable after calculating physics
			 * 
			 * virtual because actor::local will add self to active transform list
			 */
			virtual void							v_set_pose_data(
					gal::math::pose const & pose);
		protected:
			void								__set_pose_data(
					gal::math::pose const & pose);
		public:
			virtual std::weak_ptr<neb::fnd::core::shape::base>		createShapeCube(
					gal::math::pose const & pose,
					double size);
			/** @brief
			 *
			 */
			virtual std::weak_ptr<neb::fnd::core::shape::base>		createShapeHeightField(
					neb::fnd::core::shape::HeightField::desc const &);
			/** @brief
			 *
			 */
			virtual std::weak_ptr<neb::fnd::core::shape::base>		createShapeLightSpot(
					gal::math::pose const & pose,
					glm::vec3 direction);
			std::weak_ptr<neb::fnd::game::weapon::SimpleProjectile>		createWeaponSimpleProjectile(
					std::shared_ptr<neb::fnd::input::source> src,
					double size,
					double damage,
					double velocity);
			template<class Archive> void					__serialize(
					Archive & ar,
					unsigned int const & version)
			{
				ar & boost::serialization::make_nvp("flag",flag_);
				//ar & boost::serialization::make_nvp("name",name_);
				ar & boost::serialization::make_nvp("pose",pose_);
				ar & boost::serialization::make_nvp("velocity",velocity_);
				ar & boost::serialization::make_nvp("density",density_);


				ar & boost::serialization::base_object<A>(*this);
				ar & boost::serialization::base_object<S>(*this);
/*				ar & boost::serialization::make_nvp(
						"actors", neb::fnd::core::actor::util::parent);
				ar & boost::serialization::make_nvp(
						"shapes", neb::fnd::core::shape::util::parent);*/
			}
			virtual void	load(ba::polymorphic_iarchive & ar, unsigned int const &);
			virtual void	save(ba::polymorphic_oarchive & ar, unsigned int const &) const;
			BOOST_SERIALIZATION_SPLIT_MEMBER();

			virtual std::weak_ptr<neb::fnd::core::shape::base>		createShapeBase(
					gal::math::pose const & pose);
			virtual std::weak_ptr<neb::fnd::core::shape::base>		createShapeCuboid(
					neb::fnd::core::shape::cuboid::Desc const &);
			neb::fnd::core::actor::util::flag			flag_;
			gal::math::pose					pose_;
			glm::vec3						velocity_;
			float							density_;
			double							health_;
			neb::phx::filter::data					simulation_;
			neb::phx::filter::data					scene_query_;
		public:
			//std::shared_ptr<>		_M_graphics_object;
			//std::shared_ptr<neb::fnd::plug::gfx::core::actor::Base>		_M_graphics_object;
			//std::shared_ptr<neb::fnd::plug::gfx::core::actor::Base>		_M_graphics_object;
	};
}}}}

#endif

#ifndef NEBULA_ACTOR_BASE_HH
#define NEBULA_ACTOR_BASE_HH

#include <memory>

#include <boost/signals2.hpp>

#include <boost/archive/polymorphic_xml_iarchive.hpp>
#include <boost/archive/polymorphic_xml_oarchive.hpp>
#include <boost/serialization/map.hpp>

#include <neb/core/math/pose.hpp>
#include <neb/core/filter.hpp>
#include <neb/core/core/actor/__base.hpp>
#include <neb/core/core/actor/util/decl.hpp>
#include <neb/core/core/actor/util/flag.hpp>
#include <neb/core/core/actor/util/parent.hpp>
#include <neb/core/core/shape/base.hpp>
#include <neb/core/core/shape/util/decl.hpp>
#include <neb/core/core/shape/util/parent.hpp>
#include <neb/core/core/shape/cuboid/desc.hpp>
#include <neb/core/math/serialization/glm.hpp>
#include <neb/core/game/weapon/util/parent.hpp>

namespace neb { namespace fnd { namespace core { namespace actor {
	/** @brief %base */
	class base:
		virtual public neb::fnd::core::actor::__base,
		virtual public neb::fnd::itf::serializable,
		virtual public neb::fnd::core::actor::util::parent,
		virtual public neb::fnd::core::shape::util::parent,
		virtual public neb::fnd::game::weapon::util::parent
	{
		public:
			using CHILD::get_fnd_app;
			typedef neb::fnd::util::parent<neb::fnd::core::actor::__base, neb::fnd::core::actor::util::parent>		actors;
			typedef neb::fnd::util::parent<neb::fnd::core::shape::base, neb::fnd::core::shape::util::parent>		shapes;
			//typedef neb::fnd::core::actor::__base> parent_t;
			/** @brief default constructor */
			base();
			/** @brief constructor */
			//base(std::shared_ptr<parent_t> parent);
			virtual ~base();
			virtual void						init(parent_t * const &) = 0;
			virtual void						release();
			virtual void						step(gal::etc::timestep const & ts);
			virtual neb::fnd::math::pose				getPose() const;
			virtual neb::fnd::math::pose				getPoseGlobal() const;
			bool							hasScene() const;
			neb::fnd::core::scene::base*				getScene() const;
			//std::shared_ptr<neb::fnd::core::actor::util::parent>		get_parent();
			/** @brief set pose
			 *
			 * virtual because actor::local will add self to active transform list
			 */
			virtual void						setPose(neb::fnd::math::pose const & pose);
			/** @brief
			 *
			 */
			virtual std::weak_ptr<neb::fnd::core::shape::base>		createShapeBase(
					neb::fnd::math::pose const & pose) = 0;
			/** @brief
			 *
			 */
			virtual std::weak_ptr<neb::fnd::core::shape::base>		createShapeCuboid(
					neb::fnd::core::shape::cuboid::Desc const &) = 0;
			/** @brief
			 *
			 */
			virtual std::weak_ptr<neb::fnd::core::shape::base>		createShapeCube(
					neb::fnd::math::pose const & pose,
					double size);
			/** @brief
			 *
			 */
			virtual std::weak_ptr<neb::fnd::core::shape::base>		createShapeHeightField(
					neb::fnd::core::shape::HeightField::desc const &) = 0;
			/** @brief
			 *
			 */
			virtual std::weak_ptr<neb::fnd::core::shape::base>		createShapeLightSpot(
					neb::fnd::math::pose const & pose,
					glm::vec3 direction);
			template<class Archive> void					__serialize(
					Archive & ar,
					unsigned int const & version)
			{
				ar & boost::serialization::make_nvp("flag",flag_);
				//ar & boost::serialization::make_nvp("name",name_);
				ar & boost::serialization::make_nvp("pose",pose_);
				ar & boost::serialization::make_nvp("velocity",velocity_);
				ar & boost::serialization::make_nvp("density",density_);

				ar & boost::serialization::make_nvp(
						"actors", neb::fnd::core::actor::util::parent::map_);
				ar & boost::serialization::make_nvp(
						"shapes", neb::fnd::core::shape::util::parent::map_);
			}
			virtual void	load(ba::polymorphic_iarchive & ar, unsigned int const &);
			virtual void	save(ba::polymorphic_oarchive & ar, unsigned int const &) const;
			BOOST_SERIALIZATION_SPLIT_MEMBER();
			neb::fnd::core::actor::util::flag			flag_;
			neb::fnd::math::pose					pose_;
			glm::vec3						velocity_;
			float							density_;
			double							health_;
			neb::phx::filter::data					simulation_;
			neb::phx::filter::data					scene_query_;
		public:
			/** @brief Parent */
			//weak_ptr<neb::fnd::core::actor::util::parent>		parent_;
	};
}}}}

#endif

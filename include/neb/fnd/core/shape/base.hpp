#ifndef __GLUTPP_SHAPE_H__
#define __GLUTPP_SHAPE_H__

#include <map>

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>

#include <boost/serialization/map.hpp>

#include <gal/etc/timestep.hpp>
#include <gal/stl/verbosity.hpp>

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/itf/serializable.hpp>
#include <neb/fnd/core/shape/util/parent.hpp>
#include <neb/fnd/core/shape/util/flag.hpp>
#include <neb/fnd/core/light/util/decl.hpp>
#include <neb/fnd/core/light/util/parent.hpp>
#include <neb/fnd/core/light/util/light_count.hpp>

#include <neb/fnd/plug/gfx/core/shape/util/decl.hpp>
#include <neb/fnd/plug/phx/core/shape/util/decl.hpp>
#include <neb/fnd/plug/ObjectParent.hpp>

namespace neb { namespace fnd { namespace core { namespace shape {
	class base:
		public gal::tmp::Verbosity<neb::fnd::core::shape::base>,
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::itf::serializable,
		virtual public neb::fnd::core::shape::util::parent,
		virtual public neb::fnd::core::light::util::parent,
		virtual public neb::fnd::tmp::Child<neb::fnd::core::shape::util::parent>,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::gfx::core::shape::Base>,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::phx::core::shape::Base>
	{
	public:
		using CHILD::get_fnd_app;
		using gal::tmp::Verbosity<neb::fnd::core::shape::base>::printv;
		typedef neb::fnd::core::shape::util::parent S;
		typedef neb::fnd::core::light::util::parent L;
		typedef neb::fnd::plug::Parent<neb::fnd::plug::gfx::core::shape::Base> G;
		typedef neb::fnd::plug::Parent<neb::fnd::plug::phx::core::shape::Base> P;
		typedef neb::fnd::core::light::base LIGHT;
		base();
		virtual ~base();
		virtual void		init(parent_t * const &);
		void			release();
		void			step(gal::etc::timestep const & ts);
		virtual void		v_set_pose_data(
				gal::math::pose const & pose_global);
	protected:
		void			__set_pose_data(
				gal::math::pose const & pose_global);
	public:
		bool							hasScene();
		neb::fnd::core::scene::base*				getScene();
		gal::math::pose						getPose() const;
		gal::math::pose						getPoseGlobal() const;
		virtual std::weak_ptr<LIGHT>		createLightPoint();
		virtual std::weak_ptr<LIGHT>		createLightSpot(glm::vec3);
		virtual std::weak_ptr<LIGHT>		createLightDirectional(glm::vec3);
	public:
		/*			virtual void	load(ba::binary_iarchive & ar, unsigned int const &) {}
					virtual void	save(ba::binary_oarchive & ar, unsigned int const &) const {}
					virtual void	load(ba::xml_iarchive & ar, unsigned int const &) {}
					virtual void	save(ba::xml_oarchive & ar, unsigned int const &) const {}*/
		virtual void	load(ba::polymorphic_iarchive & ar, unsigned int const &);
		virtual void	save(ba::polymorphic_oarchive & ar, unsigned int const &) const;
		BOOST_SERIALIZATION_SPLIT_MEMBER();
	protected:
			template<class Archive>	void				__serialize(
					Archive & ar, unsigned int const & version)
			{
				printv(DEBUG, "%s\n", __PRETTY_FUNCTION__);
				ar & boost::serialization::make_nvp("flag",flag_);
				ar & boost::serialization::make_nvp("pose",pose_);
				ar & boost::serialization::make_nvp("scale",scale_);
				ar & boost::serialization::make_nvp("image",image_);
				ar & boost::serialization::make_nvp("normal",normal_);
				//ar & BOOST::SERIALIZATION::make_NVP("lights", neb::fnd::core::light::util::parent::map_);

				ar & boost::serialization::base_object<S>(*this);
				ar & boost::serialization::base_object<L>(*this);
			}
		public:
			neb::fnd::core::shape::util::flag		flag_;
			/** @brief pose */
			gal::math::pose				pose_;
			/** @brief scale */
			glm::vec3					scale_;
			/** @brief Name of image file */
			std::string					image_;
			/** @brief Name of normal map file */
			std::string					normal_;
	};
}}}}

#endif


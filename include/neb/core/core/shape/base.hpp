#ifndef __GLUTPP_SHAPE_H__
#define __GLUTPP_SHAPE_H__

#include <map>

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>

#include <gal/etc/timestep.hpp>

#include <gal/stl/child.hpp>

#include <neb/core/core/shape/util/parent.hpp>
#include <neb/core/core/shape/util/flag.hpp>
#include <neb/core/core/light/util/decl.hpp>
#include <neb/core/core/light/util/parent.hpp>
#include <neb/core/core/light/util/light_count.hpp>

namespace neb { namespace core { namespace core { namespace shape {
	class base:
		virtual public neb::itf::shared,
		virtual public neb::core::core::shape::util::parent,
		virtual public neb::core::core::light::util::parent,
		virtual public gal::stl::child<neb::core::core::shape::util::parent>
	{
		public:

			base();
			virtual ~base();
			void			init();
			void			release();
			void			step(gal::etc::timestep const & ts);
			virtual void		callbackPose(neb::core::pose const & pose_global) = 0;
			/** @name Accessors @{ */
			neb::core::pose						getPose() const;
			neb::core::pose						getPoseGlobal() const;
			/** @} */
			virtual weak_ptr<neb::core::core::light::base>		createLightPoint() = 0;
			virtual weak_ptr<neb::core::core::light::base>		createLightDirectional(glm::vec3) = 0;
		public:
			template<class Archive>	void	serialize(
					Archive & ar, unsigned int const & version)
			{
				ar & boost::serialization::make_nvp("flag",flag_);
				ar & boost::serialization::make_nvp("pose",pose_);
				ar & boost::serialization::make_nvp("scale",scale_);
				ar & boost::serialization::make_nvp("image",image_);
				ar & boost::serialization::make_nvp("normal",normal_);
			}

		public:
			neb::core::core::shape::util::flag		flag_;
			/** @brief pose */
			neb::core::pose					pose_;
			/** @brief scale */
			glm::vec3					scale_;
			/** @brief Name of image file */
			string						image_;
			/** @brief Name of normal map file */
			string						normal_;
		public:


	};
}}}}

#endif


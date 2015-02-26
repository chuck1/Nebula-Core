#ifndef __GLUTPP_LIGHT_H__
#define __GLUTPP_LIGHT_H__

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>

#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/itf/serializable.hpp>
#include <neb/fnd/math/color/color.hpp>
#include <neb/fnd/math/serialization/glm.hpp>
#include <neb/fnd/math/pose.hpp>
#include <neb/fnd/core/scene/util/decl.hpp>
#include <neb/fnd/core/light/util/decl.hpp>
#include <neb/fnd/core/light/util/Flag.hpp>
#include <neb/fnd/core/light/util/light_count.hpp>
#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/plug/gfx/util/decl.hpp>
#include <neb/fnd/plug/ObjectParent.hpp>

namespace neb { namespace fnd { namespace core { namespace light {
	class base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::itf::serializable,
		virtual public neb::fnd::tmp::Child<neb::fnd::core::light::util::parent>,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::gfx::core::light::Base>
	{
		public:
			using CHILD::get_fnd_app;
			typedef neb::fnd::plug::Parent<neb::fnd::plug::gfx::core::light::Base> G;
			base();
			virtual void				v_set_pose_data(neb::fnd::math::pose const &);
			virtual void				init(neb::fnd::core::light::util::parent * const & p);
			//virtual void				release();
			virtual void				step(gal::etc::timestep const & ts);
			neb::fnd::math::pose			getPose();
			neb::fnd::math::pose			getPoseGlobal();
			glm::vec4				getPos();
			bool					hasScene() const;
			neb::fnd::core::scene::base*		getScene();
		private:
			template<class Archive> void		serializeTemplate(
					Archive & ar, unsigned int const & version)
			{
				//ar & boost::serialization::make_nvp("i",i_);
				ar & boost::serialization::make_nvp("flag",flag_);
				//ar & boost::serialization::make_nvp("pos",pos_);
				/*
				   ar & boost::serialization::make_nvp("atten_const",atten_const_);
				   ar & boost::serialization::make_nvp("atten_linear",atten_linear_);
				   ar & boost::serialization::make_nvp("atten_quad",atten_quad_);*/
			}
		public:
			virtual void				load(
					boost::archive::polymorphic_iarchive & ar,
					unsigned int const & version);
			virtual void				save(
					boost::archive::polymorphic_oarchive & ar,
					unsigned int const & version) const;
			BOOST_SERIALIZATION_SPLIT_MEMBER();
		public:
			neb::fnd::core::light::util::flag			flag_;
			neb::fnd::math::pose					pose_;
	};
}}}}

#endif


#ifndef NEBULA_CORE_LIGHT_UTIL_PARENT_HH
#define NEBULA_CORE_LIGHT_UTIL_PARENT_HH

#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/itf/Pose.hpp>
#include <neb/fnd/util/parent.hpp>
#include <neb/fnd/core/scene/util/decl.hpp>
#include <neb/fnd/core/shape/util/cast.hpp>
#include <neb/fnd/core/light/base.hpp>

namespace neb { namespace fnd { namespace core { namespace light { namespace util {

	class parent:
		virtual public neb::fnd::util::parent<neb::fnd::core::light::base, parent>,
		virtual public neb::fnd::core::shape::util::cast,
		virtual public neb::fnd::itf::Pose
	{
		public:
			virtual ~parent() {}
			//bool							hasScene();
			//std::weak_ptr<neb::fnd::core::scene::base>		getScene();
			void							callbackPose(gal::math::pose const &);
			neb::fnd::app::Base * const				get_fnd_app();
	};

}}}}}

#endif

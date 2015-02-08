#ifndef NEBULA_CORE_LIGHT_UTIL_PARENT_HH
#define NEBULA_CORE_LIGHT_UTIL_PARENT_HH

#include <neb/core/itf/Pose.hpp>
#include <neb/core/util/parent.hpp>
#include <neb/core/core/scene/util/decl.hpp>
#include <neb/core/core/shape/util/cast.hpp>
#include <neb/core/core/light/__base.hpp>

namespace neb { namespace fnd { namespace core { namespace light { namespace util {

	class parent:
		virtual public neb::fnd::util::parent<neb::fnd::core::light::__base, parent>,
		virtual public neb::fnd::core::shape::util::cast,
		virtual public neb::fnd::itf::Pose
	{
		public:
			virtual ~parent() {}
			//bool							hasScene();
			//std::weak_ptr<neb::fnd::core::scene::base>		getScene();

			void							callbackPose(neb::fnd::math::pose const &);
	};

}}}}}

#endif

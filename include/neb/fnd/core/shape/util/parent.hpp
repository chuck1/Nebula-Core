#ifndef __GLUTPP_PARENT_H__
#define __GLUTPP_PARENT_H__

#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gal/itf/shared.hpp>

#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/itf/Pose.hpp>
#include <neb/fnd/core/actor/util/decl.hpp>
#include <neb/fnd/core/actor/util/Cast.hpp>
#include <neb/fnd/core/shape/util/cast.hpp>
#include <neb/fnd/util/parent.hpp>

namespace neb { namespace fnd { namespace core { namespace shape { namespace util {
	/** @brief %parent
	 * abstract class for parent of a shape
	 *
	 * @note inheritance of neb::util::parent is non-virtual
	 */
	class parent:
		virtual public neb::fnd::util::parent<neb::fnd::core::shape::base, parent>,
		virtual public neb::fnd::core::actor::util::Cast,
		virtual public neb::fnd::core::shape::util::cast,
		virtual public neb::fnd::itf::Pose
	{
		public:
			virtual ~parent();
			void				callbackPose(neb::fnd::math::pose const & pose);
			neb::fnd::app::Base * const	get_fnd_app();
	};
}}}}}

#endif


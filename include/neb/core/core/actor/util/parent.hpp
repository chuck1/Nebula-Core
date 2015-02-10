#ifndef __GRU_ACTOR_PARENT_H__
#define __GRU_ACTOR_PARENT_H__

#include <map>

#include <gal/itf/shared.hpp>

#include <neb/core/util/parent.hpp>

#include <neb/core/core/actor/__base.hpp>
#include <neb/core/core/actor/util/decl.hpp>
#include <neb/core/core/actor/util/Cast.hpp>
#include <neb/core/core/scene/util/cast.hpp>
#include <neb/core/core/scene/util/decl.hpp>
#include <neb/core/itf/Pose.hpp>

namespace neb { namespace fnd { namespace core { namespace actor { namespace util {
	/** @brief %arent
	 * abstract class for parent of an %actor
	 */
	class parent:
		virtual public neb::fnd::util::parent<neb::fnd::core::actor::__base, parent>,
		virtual public neb::fnd::core::scene::util::cast,
		virtual public neb::fnd::core::actor::util::Cast,
		virtual public neb::fnd::itf::Pose
	{
		public:
			parent();
			virtual ~parent();
			neb::fnd::app::Base*		get_app();
		public:
			//shared_ptr<neb::fnd::core::scene::base>			getScene();
	};
}}}}}

#endif


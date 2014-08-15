#ifndef __GRU_ACTOR_PARENT_H__
#define __GRU_ACTOR_PARENT_H__

#include <map>

#include <gal/std/shared.hpp>

#include <neb/core/util/parent.hpp>

#include <neb/core/core/actor/__base.hpp>
#include <neb/core/core/actor/util/Types.hh>
#include <neb/core/core/actor/util/Cast.hh>
#include <neb/core/core/scene/util/cast.hpp>
#include <neb/core/core/scene/util/decl.hpp>
#include <neb/core/interface/Pose.hh>

namespace neb {
	namespace core {
	namespace actor {
		namespace util {




		/** @brief @Parent
		 * abstract class for parent of an @Actor
		 */
		class parent:
			virtual public neb::util::parent<neb::actor::__base>,
			virtual public neb::core::core::scene::util::cast,
			virtual public neb::core::Pose
		{
			public:
				parent();
				virtual ~parent();

				virtual void						init();
				virtual void						release();
			public:
				sp::shared_ptr<neb::core::core::scene::base>			getScene();
		};



	}
	}
}
}

#endif


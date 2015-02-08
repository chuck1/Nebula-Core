#ifndef PHYSX_GAME_AI_UTIL_PARENT_HPP
#define PHYSX_GAME_AI_UTIL_PARENT_HPP


#include <neb/core/util/parent.hpp>

#include <neb/core/game/ai/base.hpp>

namespace neb { namespace fnd { namespace game { namespace ai { namespace util {


	/** @brief @Parent
	 * abstract class for parent of a shape
	 */
	class parent:
		virtual public neb::fnd::util::parent<neb::fnd::game::ai::base, parent>
	{
		public:
			virtual ~parent() {}
	};



}}}}}

#endif






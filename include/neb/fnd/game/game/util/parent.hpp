#ifndef __GRU_GAME_GAME_UTIL_PARENT_HPP__
#define __GRU_GAME_GAME_UTIL_PARENT_HPP__

#include <gal/itf/shared.hpp>

#include <neb/fnd/util/parent.hpp>
#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/game/game/base.hpp>

namespace neb { namespace fnd { namespace game { namespace game { namespace util {
	/** @brief parent
	 */
	class parent:
		virtual public neb::fnd::util::parent<neb::fnd::game::game::base, parent>
	{
		public:
			parent();
			virtual ~parent();
			neb::fnd::app::Base * const		get_fnd_app();
		protected:
			virtual void				__init();
		public:
	};
}}}}}

#endif


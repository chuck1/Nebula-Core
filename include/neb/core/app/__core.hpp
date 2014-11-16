#ifndef __NEBULA_APP___CORE_H__
#define __NEBULA_APP___CORE_H__

#include <neb/core/app/__base.hpp>
#include <neb/core/core/scene/util/parent.hpp>
#include <neb/core/game/game/util/parent.hpp>
#include <neb/core/game/game/util/decl.hpp>

namespace neb { namespace core { namespace app {
	class __core:
		virtual public nc::app::__base,
		virtual public nc::core::scene::util::parent,
		virtual public nc::game::game::util::parent
	{
		protected:
			//virtual void					__init();
			//virtual void					__release();
			//void						__step(gal::etc::timestep const &);
		public:
			static std::weak_ptr<nc::app::__core>		global();
			neb::core::math::pose				getPose() const;
			neb::core::math::pose				getPoseGlobal() const;
			std::shared_ptr<nc::game::game::base>		createGame(
					nc::game::game::desc const &
					);
	};
}}}

#endif




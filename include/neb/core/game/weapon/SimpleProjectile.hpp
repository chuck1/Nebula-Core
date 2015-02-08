#ifndef NEB_FND_GAME_WEAPON_SIMPLE_PROJECTILE_HPP
#define NEB_FND_GAME_WEAPON_SIMPLE_PROJECTILE_HPP

#include <neb/core/game/weapon/base.hpp>

namespace neb { namespace fnd { namespace game { namespace weapon {
	class SimpleProjectile:
		virtual public neb::fnd::game::weapon::base
	{
		public:
			SimpleProjectile();
			virtual void		connect(
					std::shared_ptr<neb::fnd::input::source> window);
			virtual int		key_fun(
					std::shared_ptr<neb::fnd::input::source> window, int, int, int, int);
			virtual void		fire();
			double			size_;
			double			velocity_;
			double			damage_;
	};
}}}}

#endif

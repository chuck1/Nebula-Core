#ifndef NEB_FND_GAME_WEAPON_SIMPLE_PROJECTILE_HPP
#define NEB_FND_GAME_WEAPON_SIMPLE_PROJECTILE_HPP

#include <gal/stl/verbosity.hpp>
#include <neb/fnd/game/weapon/base.hpp>

namespace neb { namespace fnd { namespace game { namespace weapon {
	class SimpleProjectile:
		public gal::tmp::Verbosity<neb::fnd::game::weapon::SimpleProjectile>,
		virtual public neb::fnd::game::weapon::base
	{
		public:
			using gal::tmp::Verbosity<neb::fnd::game::weapon::SimpleProjectile>::printv;
			SimpleProjectile();
			virtual void		connect(
					std::shared_ptr<neb::fnd::input::source> window);
			virtual int		keyFun(
					std::shared_ptr<neb::fnd::input::source> const & window,
					int,
					int,
					int,
					int);
			virtual void		fire();
			double			size_;
			double			velocity_;
			double			damage_;
	};
}}}}

#endif

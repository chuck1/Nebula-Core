#ifndef PHYSX_GAME_WEAPON_BASE_HPP
#define PHYSX_GAME_WEAPON_BASE_HPP

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/input/sink.hpp>
#include <neb/fnd/input/util/decl.hpp>
#include <neb/fnd/game/util/decl.hpp>

namespace neb { namespace fnd { namespace game { namespace weapon {
	class base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::input::sink,
		virtual public neb::fnd::tmp::Child<neb::fnd::game::weapon::util::parent>
	{
		public:
			typedef neb::fnd::game::weapon::util::parent parent_t;
			typedef neb::fnd::input::source SOURCE;
			base();
			virtual void					init(parent_t * const & p);
			virtual void					step(gal::etc::timestep const &);
			virtual void					connect(
					std::shared_ptr<SOURCE> src) = 0;
			virtual int					keyFun(
					std::shared_ptr<SOURCE> window, int, int, int, int) = 0;
			virtual void					fire() = 0;
			/** @brief last
			 *
			 * last time weapon was fired
			 */
			double						last_;
			/** @brief cooldown
			 */
			double						cooldown_;
	};
}}}}

#endif

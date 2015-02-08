#ifndef PHYSX_GAME_WEAPON_BASE_HPP
#define PHYSX_GAME_WEAPON_BASE_HPP

#include <gal/stl/child.hpp>

#include <neb/core/util/decl.hpp>
#include <neb/core/itf/shared.hpp>
#include <neb/core/input/sink.hpp>
#include <neb/core/input/util/decl.hpp>
#include <neb/core/game/util/decl.hpp>
//#include <neb/phx/core/actor/util/decl.hpp>

namespace neb { namespace fnd { namespace game { namespace weapon {
	class base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::input::sink,
		virtual public gal::stl::child<neb::fnd::game::weapon::util::parent>
	{
		public:
			typedef neb::fnd::game::weapon::util::parent parent_t;
			base();
			virtual std::shared_ptr<neb::fnd::app::Base>	get_app();
			virtual void					init(parent_t * const & p);
			virtual void					step(gal::etc::timestep const &) {}
			virtual void					connect(std::shared_ptr<neb::fnd::input::source> src) = 0;
			virtual int					key_fun(std::shared_ptr<neb::fnd::input::source> window, int, int, int, int) = 0;
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

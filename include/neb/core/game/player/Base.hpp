#ifndef NEBULA_PLAYER_HPP
#define NEBULA_PLAYER_HPP

namespace neb { namespace fnd { namespace game { namespace player {
	class Base
	{
		public:
			/** @brief %Actor.
			 * %Actor which the player controls
			 */
			std::weak_ptr<neb::core::actor::base>   actor_;
	};
}}}}

#endif

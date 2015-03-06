#ifndef NEBULA_SCENE_UTIL_PARENT_HH
#define NEBULA_SCENE_UTIL_PARENT_HH

#include <gal/stl/map.hpp>

#include <neb/fnd/itf/Pose.hpp>
#include <neb/fnd/util/parent.hpp>
#include <neb/fnd/core/scene/Base.hpp>
#include <neb/fnd/game/map/util/decl.hpp>

namespace neb { namespace fnd { namespace core { namespace scene { namespace util {
	/** @brief parent
	*/
	class parent:
		virtual public neb::fnd::util::parent<neb::fnd::core::scene::base, parent>,
		virtual public neb::fnd::itf::Pose
	{
		public:
			using neb::fnd::util::parent<neb::fnd::core::scene::base, parent>::step;
			neb::fnd::app::Base* const		get_fnd_app();

			typedef neb::fnd::game::map::Base GM;

			std::shared_ptr<GM>			is_fnd_game_map_base();
	};
}}}}}

#endif


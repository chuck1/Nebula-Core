#ifndef NEB_FND_CAMERA_VIEW_UTIL_CAST_HPP
#define NEB_FND_CAMERA_VIEW_UTIL_CAST_HPP

#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/camera/util/decl.hpp>

namespace neb { namespace fnd { namespace camera { namespace view { namespace util {
	class Cast:
		virtual public neb::fnd::itf::shared
	{
		public:
			typedef neb::fnd::camera::view::Base			B;
			typedef neb::fnd::camera::view::Ridealong		R;
			typedef neb::fnd::camera::view::shadow::Base		SB;
			typedef neb::fnd::camera::view::shadow::Point		SP;
			typedef neb::fnd::camera::view::shadow::Directional	SD;
			typedef neb::fnd::camera::view::shadow::Spot		SS;
			std::shared_ptr<B>	is_fnd_camera_view_base();
			std::shared_ptr<R>	is_fnd_camera_view_ridealong();
			std::shared_ptr<SB>	is_fnd_camera_view_shadow_base();
			std::shared_ptr<SP>	is_fnd_camera_view_shadow_point();
			std::shared_ptr<SD>	is_fnd_camera_view_shadow_directional();
			std::shared_ptr<SS>	is_fnd_camera_view_shadow_spot();
	};
}}}}}

#endif

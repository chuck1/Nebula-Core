#ifndef NEB_FND_CAMERA_VIEW_UTIL_CAST_HPP
#define NEB_FND_CAMERA_VIEW_UTIL_CAST_HPP

#include <neb/fnd/camera/util/decl.hpp>

namespace neb { namespace fnd { namespace camera { namespace view { namespace util {
	class Cast:
		virtual public neb::fnd::itf::shared
	{
		public:
			typedef neb::fnd::camera::view::Base			B;
			typedef neb::fnd::camera::view::Ridealong		R;
			typedef neb::fnd::camera::view::shadow::Base		SB;
			typedef neb::fnd::camera::view::shadow::Base		SP;
			typedef neb::fnd::camera::view::shadow::Base		SD;
			typedef neb::fnd::camera::view::shadow::Base		SS;
			std::shared_ptr<B>	is_fnd_camera_view_base();
	};
}}}}}

#endif

#include <neb/fnd/camera/view/util/Cast.hpp>

#include <neb/fnd/camera/view/Base.hpp>
#include <neb/fnd/camera/view/Ridealong.hpp>
#include <neb/fnd/camera/view/shadow/Base.hpp>
#include <neb/fnd/camera/view/shadow/Point.hpp>
#include <neb/fnd/camera/view/shadow/Directional.hpp>
#include <neb/fnd/camera/view/shadow/Spot.hpp>

typedef neb::fnd::camera::view::Base			B;
typedef neb::fnd::camera::view::Ridealong		R;
typedef neb::fnd::camera::view::shadow::Base		SB;
typedef neb::fnd::camera::view::shadow::Point		SP;
typedef neb::fnd::camera::view::shadow::Directional	SD;
typedef neb::fnd::camera::view::shadow::Spot		SS;

typedef neb::fnd::camera::view::util::Cast THIS;

std::shared_ptr<B>	THIS::is_fnd_camera_view_base()
{
	return std::dynamic_pointer_cast<B>(shared_from_this());
}
std::shared_ptr<R>	THIS::is_fnd_camera_view_ridealong()
{
	return std::dynamic_pointer_cast<R>(shared_from_this());
}
std::shared_ptr<SB>	THIS::is_fnd_camera_view_shadow_base()
{
	return std::dynamic_pointer_cast<SB>(shared_from_this());
}
std::shared_ptr<SP>	THIS::is_fnd_camera_view_shadow_point()
{
	return std::dynamic_pointer_cast<SP>(shared_from_this());
}
std::shared_ptr<SD>	THIS::is_fnd_camera_view_shadow_directional()
{
	return std::dynamic_pointer_cast<SD>(shared_from_this());
}
std::shared_ptr<SS>	THIS::is_fnd_camera_view_shadow_spot()
{
	return std::dynamic_pointer_cast<SS>(shared_from_this());
}


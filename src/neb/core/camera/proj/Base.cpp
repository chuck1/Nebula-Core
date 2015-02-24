#include <neb/fnd/camera/proj/Base.hpp>
#include <neb/fnd/plug/gfx/camera/proj/Base.hpp>

typedef neb::fnd::camera::proj::Base THIS;

void		THIS::load(neb::fnd::glsl::program::Base * const & p)
{
	if(_M_graphics_object)
		_M_graphics_object->load(p);
}


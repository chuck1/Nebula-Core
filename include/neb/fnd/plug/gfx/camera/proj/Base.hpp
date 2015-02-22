#ifndef NEB_FND_PLUG_GFX_CAMERA_PROJ_BASE_HPP
#define NEB_FND_PLUG_GFX_CAMERA_PROJ_BASE_HPP

#include <neb/fnd/camera/proj/Base.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace camera { namespace proj {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<neb::fnd::camera::proj::Base>
	{
		public:
			typedef neb::fnd::camera::proj::Base FND;
			virtual void		init(parent_t * const & p) = 0;
			virtual void		calculate() = 0;
	};
}}}}}}


#endif

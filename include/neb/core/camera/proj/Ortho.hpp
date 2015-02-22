#ifndef NEB_FIN_CAMERA_PROJ_ORTHO_HPP
#define NEB_FIN_CAMERA_PROJ_ORTHO_HPP

#include <neb/core/camera/proj/Base.hpp>

namespace neb { namespace fnd { namespace camera { namespace proj {
	class Ortho:
		//virtual public neb::gfx::camera::proj::Ortho,
		virtual public neb::fnd::camera::proj::Base
	{
		public:
			Ortho();
			virtual void		init(parent_t * const & p);
			virtual void		step(gal::etc::timestep const & ts);
			virtual void		release();
	};
}}}}

#endif

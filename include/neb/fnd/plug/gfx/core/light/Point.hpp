#ifndef NEB_FND_PLUG_GFX_CORE_LIGHT_POINT_HPP
#define NEB_FND_PLUG_GFX_CORE_LIGHT_POINT_HPP

#include <neb/fnd/plug/gfx/core/light/Base.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace core { namespace light {
	class Point:
		virtual public neb::fnd::plug::gfx::core::light::Base
	{
		public:
			typedef neb::fnd::core::light::Point FND;
/*
			virtual void			v_set_pose_data(
					FND * const & ptr,
					neb::fnd::math::pose const & global_pose) = 0;
			virtual void			draw(
					FND * const & ptr,
					neb::fnd::glsl::program::Base const * const & p,
					neb::fnd::math::pose const & pose) = 0;
			virtual void			model_load(
					FND * const & ptr,
					neb::fnd::glsl::program::Base const * const & p,
					neb::fnd::math::pose const & pose) = 0;
					*/
				//virtual void			v_set_pose_data(neb::fnd::math::pose const & pose) = 0;
	};
}}}}}}


#endif

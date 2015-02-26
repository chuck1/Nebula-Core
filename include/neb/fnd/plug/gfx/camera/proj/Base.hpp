#ifndef NEB_FND_PLUG_GFX_CAMERA_PROJ_BASE_HPP
#define NEB_FND_PLUG_GFX_CAMERA_PROJ_BASE_HPP

#include <glm/glm.hpp>

#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/camera/util/decl.hpp>
#include <neb/fnd/glsl/program/util/decl.hpp>

#include <neb/fnd/plug/Object.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace camera { namespace proj {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::plug::Object<
				neb::fnd::plug::gfx::camera::proj::Base,
				neb::fnd::camera::proj::Base>
	{
		public:
			typedef neb::fnd::camera::proj::Base FND;
			virtual void		init(parent_t * const & p) = 0;
			virtual void		load(neb::fnd::glsl::program::Base * const & p) = 0;
			virtual void		calculate() = 0;
			virtual glm::mat4	proj() = 0;
	};
}}}}}}


#endif

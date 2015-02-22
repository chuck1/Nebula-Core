#ifndef NEBULA_GRAPHICS_RENDER_DESC_HPP
#define NEBULA_GRAPHICS_RENDER_DESC_HPP

#include <neb/fnd/itf/shared.hpp>

#include <neb/fnd/camera/util/decl.hpp>
#include <neb/fnd/glsl/util/decl.hpp>
#include <neb/fnd/glsl/program/util/decl.hpp>

namespace neb { namespace fnd {

	class RenderDesc
	{
		public:
			RenderDesc();
			RenderDesc(
					camera::view::Base* nv,
					camera::proj::Base* np,
					glsl::program::Base* nd3,
					glsl::program::Base* nd3_HF,
					glsl::program::Base* nd3_inst);
			camera::view::Base*		v;
			camera::proj::Base*		p;
			glsl::program::Base*		d3;
			glsl::program::Base*		d3_HF;
			glsl::program::Base*		d3_inst;
	};
}}

#endif

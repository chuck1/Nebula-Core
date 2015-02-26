#ifndef NEB_FND_PLUG_GFX_CAMERA_VIEW_BASE_HPP
#define NEB_FND_PLUG_GFX_CAMERA_VIEW_BASE_HPP

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/camera/util/decl.hpp>

#include <neb/fnd/plug/Object.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace camera { namespace view {
	class Base:
		virtual public gal::itf::shared,
		virtual public neb::fnd::plug::Object<
				neb::fnd::plug::gfx::camera::view::Base,
				neb::fnd::camera::view::Base>
	{
		public:
			typedef neb::fnd::camera::view::Base FND;
			virtual void		load(neb::fnd::glsl::program::Base * const & p) = 0;
	};
}}}}}}

#endif

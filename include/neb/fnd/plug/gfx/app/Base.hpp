#ifndef NEB_FND_PLUG_GFX_APP_BASE_HPP
#define NEB_FND_PLUG_GFX_APP_BASE_HPP

#include <neb/fnd/input/util/decl.hpp>
#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/math/color/color.hpp>
#include <neb/fnd/glsl/program/util/decl.hpp>
#include <neb/fnd/plug/Object.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace app {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::plug::Object<
				neb::fnd::plug::gfx::app::Base,
				neb::fnd::app::Base>
	{
		public:
			typedef std::shared_ptr<neb::fnd::input::js> S_JS;
			virtual void		init(parent_t * const & p) = 0;
			virtual void		onFirstContext() = 0;
			virtual double		get_time() = 0;
			/*
			 * get data from input devices
			 */
			virtual void		update() = 0;
			virtual S_JS		get_joystick(int i = -1) = 0;
			virtual std::shared_ptr<neb::fnd::glsl::program::Base>		get_program_text() = 0;
			virtual std::shared_ptr<neb::fnd::glsl::program::Base>		get_program_tex() = 0;
			virtual std::shared_ptr<neb::fnd::glsl::program::Base>		get_program_simple3() = 0;
			virtual void		draw_quad(
					float x,
					float y,
					float w,
					float h,
					neb::fnd::math::color::color color) = 0;
			virtual void		draw_text(
					float x,
					float y,
					float sx,
					float sy,
					neb::fnd::math::color::color color,
					std::string text,
					std::string::size_type cursor_pos) = 0;
	};
}}}}}

#endif

#ifndef NEB_FND_PLUG_GFX_WINDOW_BASE_HPP
#define NEB_FND_PLUG_GFX_WINDOW_BASE_HPP

#include <glm/glm.hpp>

//#include <neb/fnd/window/Base.hpp>
#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/itf/shared.hpp>

#include <neb/fnd/plug/Object.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace window {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::plug::Object<
				neb::fnd::plug::gfx::window::Base,
				neb::fnd::window::Base>
	{
		public:
			typedef neb::fnd::window::Base FND;
			virtual void		init(parent_t * const & p) = 0;
			virtual void		render() = 0;
			//virtual void		setTexture(
			//		std::shared_ptr<neb::fnd::itf::shared> tex) = 0;
			virtual void		printScreen() = 0;
			virtual void		resize() = 0;
			virtual void		makeCurrent() = 0;
			virtual int		get_width() = 0;
			virtual int		get_height() = 0;
			virtual glm::vec2	getCursorPosNDC() = 0;
	};
}}}}}


#endif

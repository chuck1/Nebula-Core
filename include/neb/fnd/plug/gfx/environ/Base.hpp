#ifndef NEB_FND_PLUG_GFX_ENVIRON_BASE_HPP
#define NEB_FND_PLUG_GFX_ENVIRON_BASE_HPP

#include <neb/fnd/environ/Base.hpp>

#include <neb/fnd/plug/Object.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace environ {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::plug::Object<
				neb::fnd::plug::gfx::environ::Base,
				neb::fnd::environ::Base>
	{
		public:
			typedef neb::fnd::environ::Base FND;
			virtual void		init(parent_t * const & p) = 0;
			virtual void		render(neb::fnd::context::Base * const & context) = 0;
			virtual void		resize(int w, int h) = 0;
			//virtual void		setTexture(
			//		std::shared_ptr<neb::fnd::itf::shared> tex) = 0;
	};
}}}}}


#endif

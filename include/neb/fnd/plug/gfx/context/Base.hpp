#ifndef NEB_FND_PLUG_GFX_CONTEXT_BASE_HPP
#define NEB_FND_PLUG_GFX_CONTEXT_BASE_HPP

#include <neb/fnd/context/Base.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace context {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<neb::fnd::context::Base>
	{
		public:
			typedef neb::fnd::context::Base FND;
			virtual void		init(parent_t * const & p) = 0;
			virtual void		render() = 0;
			virtual void		setTexture(
					std::shared_ptr<neb::fnd::itf::shared> tex) = 0;
	};
}}}}}


#endif

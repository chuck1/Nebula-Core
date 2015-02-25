#ifndef NEB_CORE_CONTEXT_FBO_HPP
#define NEB_CORE_CONTEXT_FBO_HPP

#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/context/Window.hpp>
#include <neb/fnd/environ/util/decl.hpp>

namespace neb { namespace fnd { namespace context {
	class FBO:
		virtual public neb::fnd::context::Window
	{
		public:
			typedef neb::fnd::environ::shadow::Directional ESD;
			virtual void			init(parent_t * const parent);
			//virtual void			render();
			virtual std::weak_ptr<ESD>	createEnvironShadowDirectional();
			virtual void			setTexture(std::shared_ptr<neb::fnd::itf::shared>);
	};
}}}

#endif


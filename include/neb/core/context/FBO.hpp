#ifndef NEB_CORE_CONTEXT_FBO_HPP
#define NEB_CORE_CONTEXT_FBO_HPP

#include <neb/core/itf/shared.hpp>
#include <neb/core/context/Window.hpp>
#include <neb/core/environ/util/decl.hpp>

namespace neb { namespace fnd { namespace context {
	class FBO:
		virtual public neb::fnd::context::Window
	{
		public:
			typedef neb::fnd::environ::shadow::Directional E;

			virtual std::weak_ptr<E>		createEnvironShadowDirectional() = 0;
			virtual void				setTexture(std::shared_ptr<neb::fnd::itf::shared> texture) = 0;
	};
}}}

#endif


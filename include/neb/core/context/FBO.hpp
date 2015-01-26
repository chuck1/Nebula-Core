#ifndef NEB_CORE_CONTEXT_FBO_HPP
#define NEB_CORE_CONTEXT_FBO_HPP

#include <neb/core/context/Base.hpp>
#include <neb/core/environ/util/decl.hpp>

namespace neb { namespace core { namespace context {
	class FBO:
		virtual public neb::core::context::Base
	{
		public:
			typedef neb::core::environ::shadow::Directional E;
			virtual std::weak_ptr<E>		createEnvironShadowDirectional();
			virtual void				setTexture(std::shared_ptr<neb::core::itf::shared> texture);
	};
}}}

#endif

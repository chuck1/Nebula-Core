#ifndef NEB_CORE_CONTEXT_FBOM_HPP
#define NEB_CORE_CONTEXT_FBOM_HPP

#include <neb/core/context/Base.hpp>
#include <neb/core/environ/util/decl.hpp>

namespace neb { namespace core { namespace context {
	class FBOM:
		virtual public neb::core::context::Base
	{
		public:
			typedef neb::core::environ::shadow::Directional E;
			virtual std::weak_ptr<E>		createEnvironShadowPoint() = 0;
			virtual std::weak_ptr<E>		createEnvironShadowDirectional() = 0;
			virtual void				setTexture(std::shared_ptr<neb::core::itf::shared> texture) = 0;
	};
}}}

#endif

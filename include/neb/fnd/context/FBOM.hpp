#ifndef NEB_CORE_CONTEXT_FBOM_HPP
#define NEB_CORE_CONTEXT_FBOM_HPP

#include <neb/fnd/itf/shared.hpp>
#include <neb/fnd/context/Base.hpp>
#include <neb/fnd/environ/util/decl.hpp>

namespace neb { namespace fnd { namespace context {
	class FBOM:
		virtual public neb::fnd::context::Base
	{
		public:
			typedef neb::fnd::environ::shadow::Point ESP;
			typedef neb::fnd::environ::shadow::Directional ESD;

			virtual std::weak_ptr<ESP>		createEnvironShadowPoint();
			virtual std::weak_ptr<ESD>		createEnvironShadowDirectional();

			virtual void				setTexture(std::shared_ptr<neb::fnd::itf::shared> texture);

			virtual void		init(parent_t * const parent);
	};
}}}

#endif

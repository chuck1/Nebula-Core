#ifndef NEB_CORE_CONTEXT_BASE_HPP
#define NEB_CORE_CONTEXT_BASE_HPP

#include <neb/core/util/decl.hpp>

namespace neb { namespace core { namespace context {
	class Base
	{
		public:
			virtual void		render() = 0;
			virtual void		setDrawable(std::shared_ptr<neb::core::drawable::Base>) = 0;
	};
}}}

#endif

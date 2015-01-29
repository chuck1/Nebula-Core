#ifndef NEB_CORE_CONTEXT_BASE_HPP
#define NEB_CORE_CONTEXT_BASE_HPP

#include <gal/stl/child.hpp>

#include <neb/core/context/util/decl.hpp>
#include <neb/core/environ/util/Parent.hpp>
#include <neb/core/util/decl.hpp>

namespace neb { namespace core { namespace context {
	class Base:
		virtual public gal::stl::child<neb::core::context::util::Parent>,
		virtual public neb::core::environ::util::Parent
	{
		public:
			virtual void		init(parent_t * const parent) = 0;
			virtual void		render() = 0;
			virtual void		setDrawable(std::shared_ptr<neb::core::drawable::Base>) = 0;
	};
}}}

#endif

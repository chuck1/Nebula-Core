#ifndef NEB_CORE_CONTEXT_BASE_HPP
#define NEB_CORE_CONTEXT_BASE_HPP

#include <gal/etc/timestep.hpp>

#include <neb/core/tmp/Child.hpp>
#include <neb/core/context/util/decl.hpp>
#include <neb/core/environ/util/Parent.hpp>
#include <neb/core/util/decl.hpp>

namespace neb { namespace fnd { namespace context {
	class Base:
		virtual public neb::fnd::tmp::Child<neb::fnd::context::util::Parent>,
		virtual public neb::fnd::environ::util::Parent
	{
		public:
			using CHILD::get_fnd_app;
			virtual void		init(parent_t * const parent) = 0;
			virtual void		step(gal::etc::timestep const & ts) = 0;
			virtual void		render() = 0;
			virtual void		setDrawable(std::shared_ptr<neb::fnd::drawable::Base>) = 0;
			virtual void		setEnviron(std::shared_ptr<neb::fnd::environ::Base>) = 0;
			virtual std::shared_ptr<neb::fnd::environ::Base>	get_environ() = 0;
	};
}}}

#endif

#ifndef NEB_CORE_CONTEXT_BASE_HPP
#define NEB_CORE_CONTEXT_BASE_HPP

#include <gal/etc/timestep.hpp>

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/context/util/decl.hpp>
#include <neb/fnd/environ/util/Parent.hpp>
#include <neb/fnd/util/decl.hpp>

#include <neb/fnd/plug/gfx/context/util/decl.hpp>

namespace neb { namespace fnd { namespace context {
	class Base:
		virtual public neb::fnd::tmp::Child<neb::fnd::context::util::Parent>,
		virtual public neb::fnd::environ::util::Parent
	{
		public:
			using CHILD::get_fnd_app;
			virtual void		init(parent_t * const parent) = 0;
			virtual void		step(gal::etc::timestep const & ts);
			virtual void		render();
			virtual void		setDrawable(std::shared_ptr<neb::fnd::drawable::Base>);
			virtual void		setEnviron(std::shared_ptr<neb::fnd::environ::Base>);

			//virtual std::shared_ptr<neb::fnd::environ::Base>	get_environ() = 0;

			//std::shared_ptr<neb::gfx::environ::base>		environ_;

			std::shared_ptr<neb::fnd::plug::gfx::context::Base>	_M_graphics_object;
	};
}}}

#endif

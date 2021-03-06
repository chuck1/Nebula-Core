#ifndef NEB_CORE_CONTEXT_BASE_HPP
#define NEB_CORE_CONTEXT_BASE_HPP

#include <gal/etc/timestep.hpp>

#include <neb/fnd/tmp/Child.hpp>
#include <neb/fnd/context/util/decl.hpp>
#include <neb/fnd/environ/util/Parent.hpp>
#include <neb/fnd/util/decl.hpp>

#include <neb/fnd/plug/ObjectParent.hpp>
#include <neb/fnd/plug/gfx/context/util/decl.hpp>
#include <neb/fnd/plug/gfx/context/Base.hpp>

namespace neb { namespace fnd { namespace context {
	class Base:
		public gal::tmp::Verbosity<neb::fnd::context::Base>,
		virtual public neb::fnd::tmp::Child<neb::fnd::context::util::Parent>,
		virtual public neb::fnd::environ::util::Parent,
		virtual public neb::fnd::plug::Parent<neb::fnd::plug::gfx::context::Base>
	{
		public:
			using gal::tmp::Verbosity<neb::fnd::context::Base>::printv;
			using CHILD::get_fnd_app;
			typedef neb::fnd::plug::Parent<neb::fnd::plug::gfx::context::Base> G;
			virtual void		init(parent_t * const & parent);
			virtual void		step(gal::etc::timestep const & ts);
			virtual void		render();
			void			resize(int w, int h);
			//virtual void		setDrawable(std::shared_ptr<neb::fnd::drawable::Base>);
			//virtual void		setEnviron(std::shared_ptr<neb::fnd::environ::Base>);
			//virtual std::shared_ptr<neb::fnd::environ::Base>	get_environ() = 0;
			//std::shared_ptr<neb::gfx::environ::base>		environ_;
	};
}}}

#endif

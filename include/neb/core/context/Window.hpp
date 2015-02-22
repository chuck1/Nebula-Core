#ifndef NEB_CORE_CONTEXT_WINDOW_HPP
#define NEB_CORE_CONTEXT_WINDOW_HPP

#include <neb/core/context/Base.hpp>
#include <neb/core/environ/util/decl.hpp>

namespace neb { namespace fnd { namespace context {
	class Window:
		virtual public neb::fnd::context::Base
	{
		public:
			typedef neb::fnd::environ::Base EB;
			typedef neb::fnd::environ::Two ET;
			typedef neb::fnd::environ::SceneDefault ESD;
			typedef neb::fnd::environ::shadow::Directional E;

			virtual void		init(parent_t * const parent);
			virtual void		step(gal::etc::timestep const & ts);
			virtual void		render();

			/*
			virtual std::weak_ptr<ET>		createEnvironTwo() = 0;
			virtual std::weak_ptr<ESD>		createEnvironSceneDefault() = 0;
			virtual std::weak_ptr<E>		createEnvironShadowDirectional() = 0;
			*/

			//virtual void				setTexture(std::shared_ptr<neb::fnd::itf::shared> texture);
	};
}}}

#endif

#ifndef NEB_FND_TMP_CHILD_HPP
#define NEB_FND_TMP_CHILD_HPP

#include <gal/stl/child.hpp>

#include <neb/fnd/util/decl.hpp>

namespace neb { namespace fnd { namespace tmp {
	template<typename T> class Child:
		virtual public gal::stl::child<T>
	{
		public:
			typedef neb::fnd::tmp::Child<T> CHILD;
			neb::fnd::app::Base*	get_fnd_app()
			{
				auto p = gal::stl::child<T>::getParent();
				assert(p);
				return p->get_fnd_app();
			}
	};
	template<> class Child<neb::fnd::app::Base>:
		virtual public gal::stl::child<neb::fnd::app::Base>
	{
		public:
			typedef neb::fnd::tmp::Child<neb::fnd::app::Base> CHILD;
			neb::fnd::app::Base*	get_fnd_app()
			{
				auto app = gal::stl::child<neb::fnd::app::Base>::getParent();
				assert(app);
				return app;
			}
	};
}}}

#endif

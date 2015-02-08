#ifndef NEB_FND_TMP_CHILD_HPP
#define NEB_FND_TMP_CHILD_HPP

#include <gal/stl/child.hpp>

#include <neb/core/util/decl.hpp>

namespace neb { namespace fnd { namespace tmp {
	template<typename T> class Child:
		virtual public gal::stl::child<T>
	{
		public:
			neb::fnd::app::Base*	get_app()
			{
				auto p = gal::stl::child<T>::getParent();
				assert(p);
				return p->get_app();
			}
	};
	template<> class Child<neb::fnd::app::Base>:
		virtual public gal::stl::child<neb::fnd::app::Base>
	{
		public:
			neb::fnd::app::Base*	get_app()
			{
				auto app = gal::stl::child<neb::fnd::app::Base>::getParent();
				assert(app);
				return app;
			}
	};
}}}

#endif

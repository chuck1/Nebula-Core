#ifndef NEB_FND_PLUG_OBJECT_HPP
#define NEB_FND_PLUG_OBJECT_HPP

#include <gal/itf/shared.hpp>
#include <gal/dll/helper.hpp>

#include <neb/fnd/plug/ObjectParent.hpp>

namespace neb { namespace fnd { namespace plug {
	template<typename T>
	class Object:
		virtual public neb::fnd::tmp::Child< neb::fnd::plug::Parent<T> >
	{
		public:
			typedef neb::fnd::plug::Parent<T> parent_t;
			virtual void		init(parent_t * const & parent) = 0;
	};
}}}

#endif

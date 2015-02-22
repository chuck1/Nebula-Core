#ifndef NEB_FND_PLUG_GFX_APP_BASE_HPP
#define NEB_FND_PLUG_GFX_APP_BASE_HPP

#include <neb/core/util/decl.hpp>
#include <neb/core/itf/shared.hpp>
#include <neb/core/tmp/Child.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace app {
	class Base:
		virtual public neb::fnd::itf::shared,
		virtual public neb::fnd::tmp::Child<neb::fnd::app::Base>
	{
		public:
			virtual void		init(parent_t * const & p);
			/*
			 * get data from input devices
			 */
			virtual void		update() = 0;
	};
}}}}}

#endif

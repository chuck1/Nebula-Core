#ifndef __NEBULA_APP___CORE_H__
#define __NEBULA_APP___CORE_H__

#include <neb/core/app/__base.hpp>
#include <neb/core/scene/util/Parent.hh>
//#include <neb/gfx/GUI/Layout/util/Parent.hh>

namespace neb {
	namespace app {
		class __core:
			virtual public neb::app::__base,
			virtual public neb::core::scene::util::parent
		{
			public:
				virtual void			init();
				virtual void			release() {}
				
				neb::core::pose			getPose();
				neb::core::pose			getPoseGlobal();
		};
	}
}

#endif






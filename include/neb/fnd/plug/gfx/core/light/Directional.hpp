#ifndef NEB_FND_PLUG_GFX_CORE_LIGHT_DIRECTIONAL_HPP
#define NEB_FND_PLUG_GFX_CORE_LIGHT_DIRECTIONAL_HPP

#include <neb/fnd/plug/gfx/core/light/Base.hpp>

namespace neb { namespace fnd { namespace plug { namespace gfx { namespace core { namespace light {
	class Directional:
		virtual public neb::fnd::plug::gfx::core::light::Base
	{
		public:
			typedef neb::fnd::core::light::Directional FND;
	};
}}}}}}


#endif

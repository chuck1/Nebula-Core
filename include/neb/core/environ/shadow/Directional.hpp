#ifndef NEB_CORE_ENVIRON_SHADOW_DIRECTIONAL_HPP
#define NEB_CORE_ENVIRON_SHADOW_DIRECTIONAL_HPP

#include <neb/core/environ/Base.hpp>
#include <neb/core/itf/shared.hpp>

namespace neb { namespace core { namespace environ { namespace shadow {
	class Directional:
		virtual public neb::core::environ::Base
	{
		public:
			virtual void		setLight(std::shared_ptr<neb::core::itf::shared> light);
	};
}}}}

#endif


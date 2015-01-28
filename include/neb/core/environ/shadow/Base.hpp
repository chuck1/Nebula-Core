#ifndef NEB_CORE_ENVIRON_SHADOW_BASE_HPP
#define NEB_CORE_ENVIRON_SHADOW_BASE_HPP

#include <neb/core/environ/Base.hpp>
#include <neb/core/core/light/util/decl.hpp>
#include <neb/core/itf/shared.hpp>

namespace neb { namespace core { namespace environ { namespace shadow {
	class Base:
		virtual public neb::core::environ::Base
	{
		public:
			virtual void		setLight(std::shared_ptr<neb::core::core::light::base> light) = 0;
			virtual void		setSceneEnviron(std::shared_ptr<neb::core::environ::Base> environ) = 0;
	};
}}}}

#endif

